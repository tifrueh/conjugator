// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "updatechecker.hpp"


UpdateChecker::UpdateChecker() {
    request = wxWebRequest();
}

void UpdateChecker::start(wxWindow* parent, const std::string& url, const int& requestId) {
    this->parent = parent;

    request = wxWebSession::GetDefault().CreateRequest(parent, url, requestId);
    if (!request.IsOk()) {
        wxMessageDialog* dlg = new wxMessageDialog(parent, wxT("La requête n'a pas pu être traitée."));
        dlg->ShowModal();
        return;
    }

    request.Start();
}

void UpdateChecker::showResult(wxWebRequestEvent& event) {
    switch(event.GetState()) {
        case wxWebRequest::State_Completed: {
            wxMessageDialog* dlgSuccess = new wxMessageDialog(parent, event.GetResponse().AsString());
            dlgSuccess->ShowModal();
            break;
        }
        case wxWebRequest::State_Failed: {
            wxMessageDialog* dlgFailed = new wxMessageDialog(parent, wxT("La requête a échoué"));
            dlgFailed->ShowModal();
            break;
        }
        default: {
            break;
        }
    }
}

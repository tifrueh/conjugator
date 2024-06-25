// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "config.hpp"
#include "updatechecker.hpp"


UpdateChecker::UpdateChecker() {
    this->request = wxWebRequest();
    this->session = wxWebSession::GetDefault();
    this->fail_silently = false;
}

void UpdateChecker::start(wxWindow* parent, const std::string& url, const int& requestId) {
    this->parent = parent;

    if (this->request.IsOk() && this->request.GetState() == wxWebRequest::State_Active) {
        this->request.Cancel();
    }

    this->request = session.CreateRequest(parent, url, requestId);
    if (!this->request.IsOk() && this->fail_silently == false) {
        wxMessageDialog* dlg = new wxMessageDialog(parent, _("The request wasn't able to be processed."), _("Error"));
        dlg->ShowModal();
        return;
    }

    request.Start();
}

void UpdateChecker::show_result(wxWebRequestEvent& event) {
    switch(event.GetState()) {
        case wxWebRequest::State_Completed: {
            show_result_message(event.GetResponse().AsString().ToStdString());
            break;
        }
        case wxWebRequest::State_Failed: {

            if (this->fail_silently == false) {
                wxMessageDialog *dlgFailed = new wxMessageDialog(
                    parent,
                    _("The web request failed. Please verify your internet connection."),
                    _("Error")
                );

                dlgFailed->ShowModal();
            }

            break;
        }
        default: {
            break;
        }
    }
}

std::string UpdateChecker::get_latest_version(const std::string& responseString) {
    size_t keyPos = responseString.find("\"tag_name\"");
    size_t versionPos = keyPos + 12;
    size_t versionEndPos = responseString.find("\"", versionPos);
    if (keyPos != responseString.npos) {
        return responseString.substr(versionPos, versionEndPos - versionPos);
    } else {
        return "Not found.";
    }
}

void UpdateChecker::show_result_message(const std::string& responseString) {
    std::string latestVersion = get_latest_version(responseString);
    wxString message;
    wxMessageDialog* dialog = nullptr;

    if (latestVersion != TAG_STR) {

        message = _("Your version: ") + wxString(TAG_STR) + L"\n" +
                  _("Latest version: ") + wxString(latestVersion) +
                  _("\n\nDo you want to download the latest version?");

        dialog = new wxMessageDialog(parent, message, _("Update"), wxOK | wxCANCEL);

        if (dialog->ShowModal() == wxID_OK) {
            wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugator/releases/latest"));
        }

    } else if (this->fail_silently == false) {
        dialog = new wxMessageDialog(parent, _("You are already using the latest version."), _("Update"));
        dialog->ShowModal();
    }
}

void UpdateChecker::set_fail_silently(const bool& failSilently) {
    this->fail_silently = failSilently;
}

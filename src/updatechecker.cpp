// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "config.hpp"
#include "updatechecker.hpp"


UpdateChecker::UpdateChecker() {
    request = wxWebRequest();
    session = wxWebSession::GetDefault();
    failSilently = false;
}

void UpdateChecker::start(wxWindow* parent, const std::string& url, const int& requestId) {
    this->parent = parent;

    if (request.IsOk() && request.GetState() == wxWebRequest::State_Active) {
        request.Cancel();
    }

    request = session.CreateRequest(parent, url, requestId);
    if (!request.IsOk() && failSilently == false) {
        wxMessageDialog* dlg = new wxMessageDialog(parent, _("The request wasn't able to be processed."), _("Error"));
        dlg->ShowModal();
        return;
    }

    request.Start();
}

void UpdateChecker::showResult(wxWebRequestEvent& event) {
    switch(event.GetState()) {
        case wxWebRequest::State_Completed: {
            showResultMessage(event.GetResponse().AsString().ToStdString());
            break;
        }
        case wxWebRequest::State_Failed: {

            if (failSilently == false) {
                wxMessageDialog *dlgFailed = new wxMessageDialog(
                    parent,
                    wxT("The web request failed. Please verify your internet connection."),
                    wxT("Erreur")
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

std::string UpdateChecker::getLatestVersion(const std::string& responseString) {
    size_t keyPos = responseString.find("\"tag_name\"");
    size_t versionPos = keyPos + 12;
    size_t versionEndPos = responseString.find("\"", versionPos);
    if (keyPos != responseString.npos) {
        return responseString.substr(versionPos, versionEndPos - versionPos);
    } else {
        return "Not found.";
    }
}

void UpdateChecker::showResultMessage(const std::string& responseString) {
    std::string latestVersion = getLatestVersion(responseString);
    wxString message;
    wxMessageDialog* dialog = nullptr;

    if (latestVersion != TAG_STR) {

        message = _("Your version: ") + wxString(TAG_STR) + L"\n" +
                  _("Latest version: ") + wxString(latestVersion) +
                  _("\n\nDo you want to download the latest version?");

        dialog = new wxMessageDialog(parent, message, _("Update"), wxOK | wxCANCEL);

        if (dialog->ShowModal() == wxID_OK) {
            wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugateur/releases/latest"));
        }

    } else if (failSilently == false) {
        dialog = new wxMessageDialog(parent, _("You are already using the latest version."), _("Update"));
        dialog->ShowModal();
    }
}

void UpdateChecker::setFailSilently(const bool& failSilently) {
    this->failSilently = failSilently;
}

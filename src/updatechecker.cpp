// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "config.hpp"
#include "updatechecker.hpp"


UpdateChecker::UpdateChecker() {
    request = wxWebRequest();
    session = wxWebSession::GetDefault();
}

void UpdateChecker::start(wxWindow* parent, const std::string& url, const int& requestId) {
    this->parent = parent;

    if (request.IsOk() && request.GetState() == wxWebRequest::State_Active) {
        request.Cancel();
    }

    request = session.CreateRequest(parent, url, requestId);
    if (!request.IsOk()) {
        wxMessageDialog* dlg = new wxMessageDialog(parent, wxT("La requête n'a pas pu être traitée."), wxT("Erreur"));
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

            wxMessageDialog *dlgFailed = new wxMessageDialog(
                parent,
                wxT("La requête web a échoué. Veuillez "
                "vérifier votre connexion Internet."),
                wxT("Erreur")
            );

            dlgFailed->ShowModal();
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
        return "Ne pas trouvé";
    }
}

void UpdateChecker::showResultMessage(const std::string& responseString) {
    std::string latestVersion = getLatestVersion(responseString);
    wxString message;
    wxMessageDialog* dialog = nullptr;

    if (latestVersion != TAG_STR) {

        message = L"Votre version: " + wxString(TAG_STR) + L"\n" +
                  L"Dernière version: " + wxString(latestVersion) +
                  L"\n\nEst-ce que vous voulez télécharger la dernière version?";

        dialog = new wxMessageDialog(parent, message, wxT("Mise à jour"), wxOK | wxCANCEL);

        if (dialog->ShowModal() == wxID_OK) {
            wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugateur/releases/latest"));
        }

    } else {
        dialog = new wxMessageDialog(parent, wxT("Vous utilisez déjà la dernière version."), wxT("Mise à jour"));
        dialog->ShowModal();
    }
}

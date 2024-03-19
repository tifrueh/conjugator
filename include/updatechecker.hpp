// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/webrequest.h>
#include <wx/busyinfo.h>


#include <string>


class UpdateChecker {
    public:
        UpdateChecker();
        void start(wxWindow* parent, const std::string& url, const int& requestID);
        void showResult(wxWebRequestEvent& request);

    private:
        std::string getLatestVersion(const std::string& responseString);
        void showResultMessage(const std::string& responseString);
        wxWebRequest request;
        wxWebSession session;
        wxWindow* parent;
};

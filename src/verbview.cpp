// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
#include "conjugateur.hpp"
#include "verbviewpanel.hpp"

#include "verbview.hpp"

VerbView::VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb) : wxScrolled<wxWindow>(parent, id) {
    this->verb = verb;
    verbViewPanel = new VerbViewPanel(this, wxID_ANY, this->verb);

    this->SetMinSize(wxSize(225, 300));

    setVerb(verb);
    
    this->SetVirtualSize(verbViewPanel->GetSize());
    this->SetScrollRate(0, 2);

}

void VerbView::setVerb(const verbDB::Verb &inputVerb) {
    verb = inputVerb;
    verbViewPanel->setVerb(verb);
    this->SetVirtualSize(verbViewPanel->GetSize());
}

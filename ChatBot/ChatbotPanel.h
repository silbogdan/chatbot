#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/listbox.h>

class ChatbotPanel : public wxPanel
{
public:
	ChatbotPanel(wxPanel* parent);
	void takeMessage(wxCommandEvent& event);
	wxStaticText* m_text;
	wxTextCtrl* TextCtrl2;

private:
	wxButton* send_button;
	
	wxBoxSizer* vbox;
};
enum
{
	BUTTON_SEND = wxID_HIGHEST + 3
};

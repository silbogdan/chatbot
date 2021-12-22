#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/listbox.h>
#include <wx/listctrl.h>

class ChatbotPanel : public wxPanel
{
public:
	ChatbotPanel(wxPanel* parent);
	void takeMessage(wxCommandEvent& event);
	wxStaticText* m_text;
	static wxTextCtrl* TextCtrl2;
	static wxListBox* main_chat;
	wxString b[3];
private:
	wxButton* send_button;
	
	wxBoxSizer* vbox;
};
enum
{
	BUTTON_SEND = wxID_HIGHEST + 3
};
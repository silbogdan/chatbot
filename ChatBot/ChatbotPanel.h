#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/string.h>
#include <wx/position.h>
#include <sstream>
#include <wx/dialog.h>
#include "MenuPanel.h"
#include "OpenPDF.h"
#include "Message.h"

class ChatbotPanel : public wxPanel
{
public:
	ChatbotPanel(wxPanel* parent);
	void takeMessage(wxCommandEvent& event);
	static wxTextCtrl* text_box;
	static wxListCtrl* main_chat;
	void Resize(wxSizeEvent& event);
	void search_topic(wxCommandEvent& event);
	void feeling_lucky(wxCommandEvent& event);
	void recommended(wxCommandEvent& event);
	void test_knowledge(wxCommandEvent& event);
	
private:
	wxBoxSizer* small_sizer;
	wxBoxSizer* big_sizer;
	wxBitmapButton* send_button;
	void pushMessage(Message* x);
};
enum
{
	BUTTON_SEND = wxID_HIGHEST + 3
};
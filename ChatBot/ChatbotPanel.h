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

#include "Message.h"

class ChatbotPanel : public wxPanel
{
public:
	ChatbotPanel(wxPanel* parent);
	void takeMessage(wxCommandEvent& event);
	static wxTextCtrl* text_box;
	static wxListCtrl* main_chat;
private:
	wxBoxSizer* small_sizer;
	wxBoxSizer* big_sizer;
	wxButton* send_button;
};
enum
{
	BUTTON_SEND = wxID_HIGHEST + 3
};
#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class MenuPanel : public wxPanel
{
public:
	MenuPanel(wxPanel* Parent);
private:
	wxButton* go_to_chatbot;
	wxButton* go_to_about_us;

	wxBoxSizer* vbox;
};
enum
{
	BUTTON_CHATBOT = wxID_HIGHEST + 1,
	BUTTON_ABOUT_US = wxID_HIGHEST + 2
};


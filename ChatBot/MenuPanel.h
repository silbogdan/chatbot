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
	wxButton* go_to_home;
	wxButton* go_to_chatbot;
};
enum
{
	BUTTON_HOME = wxID_HIGHEST + 1,
	BUTTON_CHATBOT = wxID_HIGHEST + 2
};


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
	wxButton* search;
	wxButton* open_file;
	wxButton* feeling_lucky;
	wxButton* recommended;
	wxButton* test_knowlodge;

	wxBoxSizer* vbox;
};
enum
{
	BUTTON_CHATBOT = wxID_HIGHEST + 1,
	BUTTON_ABOUT_US = wxID_HIGHEST + 2,
	BUTTON_SEARCH = wxID_HIGHEST + 4,
	BUTTON_OPEN_FILE = wxID_HIGHEST + 5,
	BUTTON_FEELING_LUCKY = wxID_HIGHEST + 6,
	BUTTON_RECOMMENDED = wxID_HIGHEST + 7,
	BUTTON_TEST_KNOWLEDGE = wxID_HIGHEST + 8
};


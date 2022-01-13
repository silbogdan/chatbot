#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "ChatbotPanel.h"


class MenuPanel : public wxPanel
{
public:
	MenuPanel(wxPanel* Parent);

	void hideOptionPanel(wxCommandEvent& event);
	void hideFilePanel(wxCommandEvent& event);

private:
	wxButton* go_to_chatbot;
	wxButton* go_to_about_us;

	wxButton* search;
	wxButton* open_file;
	wxButton* feeling_lucky;
	wxButton* recommended;
	wxButton* test_knowlodge;

	wxButton* open_file1;
	wxButton* open_file2;
	wxButton* open_file3;
	wxButton* open_file4;
	wxButton* cancel;

	wxBoxSizer* main_sizer;
	wxBoxSizer* navigation_sizer;
	wxBoxSizer* empty_sizer;
	wxBoxSizer* option_sizer;
	wxBoxSizer* file_sizer;
};
enum
{
	BUTTON_CHATBOT = wxID_HIGHEST + 1,
	BUTTON_ABOUT_US = wxID_HIGHEST + 2,
	BUTTON_SEARCH = wxID_HIGHEST + 4,
	BUTTON_OPEN_FILE = wxID_HIGHEST + 5,
	BUTTON_FEELING_LUCKY = wxID_HIGHEST + 6,
	BUTTON_RECOMMENDED = wxID_HIGHEST + 7,
	BUTTON_TEST_KNOWLEDGE = wxID_HIGHEST + 8,
	BUTTON_OPEN1 = wxID_HIGHEST + 9,
	BUTTON_OPEN2 = wxID_HIGHEST + 10,
	BUTTON_OPEN3 = wxID_HIGHEST + 11,
	BUTTON_OPEN4 = wxID_HIGHEST + 12,
	BUTTON_CANCEL = wxID_HIGHEST + 13
};


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
	void searchTopic(wxCommandEvent& event);
	void feelingLucky(wxCommandEvent& event);
	void recommended(wxCommandEvent& event);
	void testKnowledge(wxCommandEvent& event);
	
	static void activateSearch() { is_waiting_for_search = true; }
	static void deactivateSearch() { is_waiting_for_search = false; }
	static bool getSearchStatus() { return is_waiting_for_search; }

	~ChatbotPanel();

private:
	static bool is_waiting_for_search;
	wxBoxSizer* small_sizer;
	wxBoxSizer* big_sizer;
	wxBitmapButton* send_button;
	void pushMessage(Message* x);
	bool is_wating_for_search = 0;
	
	const std::vector<std::string> luckyInfo;

	static const wxFont* custom_font;
};
enum
{
	BUTTON_SEND = wxID_HIGHEST + 3
};

/*
* These are templates
* I suppose that they will be member functions
* I prefer that you keep the parameter order and type
* x
*/
void getSearchResult(Message* q, Message* a);
void getFactForFeelingLucky(Message* f);
void getQandAForRecommended(Message* q, Message* a);
void getStatementForTest(Message* x, bool* is_statement_true);
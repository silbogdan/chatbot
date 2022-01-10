#include "MenuPanel.h"

MenuPanel* MenuPanel::sth = NULL;
wxBoxSizer* MenuPanel::sth1 = NULL;

MenuPanel::MenuPanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{	
	box_empty = new wxBoxSizer(wxVERTICAL);

	go_to_chatbot = new wxButton(this, BUTTON_CHATBOT, _T("  Chatbot"), wxPoint(0, 0), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	go_to_about_us = new wxButton(this, BUTTON_ABOUT_US, _T("  About Us"), wxPoint(0, 30), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	search = new wxButton(this, BUTTON_SEARCH, _T(" Search"), wxPoint(0, 60), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	open_file = new wxButton(this, BUTTON_OPEN_FILE, _T(" Open File"), wxPoint(0, 90), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	feeling_lucky = new wxButton(this, BUTTON_FEELING_LUCKY, _T(" Feeling Lucky"), wxPoint(0, 120), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	recommended = new wxButton(this, BUTTON_RECOMMENDED, _T(" Recommended Q&A"), wxPoint(0, 180), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	test_knowlodge = new wxButton(this, BUTTON_TEST_KNOWLEDGE, _T(" Test Your knowloedge"), wxPoint(0, 210), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);

	//go_to_chatbot->SetBackgroundColour(wxColour(*wxWHITE));
	//go_to_about_us->SetBackgroundColour(wxColour(*wxWHITE));

	box_empty->Add(go_to_chatbot, 9, wxEXPAND | wxALL, 3);
	box_empty->Add(go_to_about_us, 9, wxEXPAND | wxALL, 3);
	auto size = box_empty->GetSize();
	auto h = size.GetHeight();
	box_empty->Add(0,h/0.5, 0);
	box_empty->Add(search, 9, wxEXPAND | wxALL, 3);
	box_empty->Add(open_file, 9, wxEXPAND | wxALL, 3);
	box_empty->Add(feeling_lucky, 9, wxEXPAND | wxALL, 3);
	box_empty->Add(recommended, 9, wxEXPAND | wxALL, 3);
	box_empty->Add(test_knowlodge, 9, wxEXPAND | wxALL, 3);

	this->SetSizer(box_empty);

	sth = this;
	sth1 = box_empty;
}

void MenuPanel::Resize_empty_spot()
{	
	sth1->Remove(2);
	auto size = sth1->GetSize();
	auto h = size.GetHeight();
	auto w = size.GetWidth();
	sth1->Insert(2,w,h/2);
}
#include "MenuPanel.h"

MenuPanel::MenuPanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{	
	main_sizer = new wxBoxSizer(wxVERTICAL);

	//the buttons that go on the top and are related to navigation
	go_to_chatbot = new wxButton(this, BUTTON_CHATBOT, _T("  Chatbot"), wxPoint(0, 0), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	go_to_about_us = new wxButton(this, BUTTON_ABOUT_US, _T("  About Us"), wxPoint(0, 30), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	
	//the buttons that go on the bottom and involve the bot
	search = new wxButton(this, BUTTON_SEARCH, _T(" Search"), wxPoint(0, 60), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	open_file = new wxButton(this, BUTTON_OPEN_FILE, _T(" Open File"), wxPoint(0, 90), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	feeling_lucky = new wxButton(this, BUTTON_FEELING_LUCKY, _T(" Feeling Lucky"), wxPoint(0, 120), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	recommended = new wxButton(this, BUTTON_RECOMMENDED, _T(" Recommended Q&A"), wxPoint(0, 180), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	test_knowlodge = new wxButton(this, BUTTON_TEST_KNOWLEDGE, _T(" Test Your knowloedge"), wxPoint(0, 210), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	
	//the button that ensures the space between the two aforementioned categories
	fake_button = new wxButton(this, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);

	go_to_chatbot->SetBackgroundColour(wxColour(*wxWHITE));
	go_to_about_us->SetBackgroundColour(wxColour(*wxWHITE));
	fake_button->SetBackgroundColour(wxColour(*wxWHITE));

	//buttons are added in the order that we want them to be shown
	main_sizer->Add(go_to_chatbot, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(go_to_about_us, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(fake_button, 3, wxEXPAND | wxALL, 3);
	main_sizer->Add(search, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(open_file, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(feeling_lucky, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(recommended, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(test_knowlodge, 1, wxEXPAND | wxALL, 3);

	this->SetSizer(main_sizer);
}
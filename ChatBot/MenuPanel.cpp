#include "MenuPanel.h"

MenuPanel::MenuPanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{	
	main_sizer = new wxBoxSizer(wxVERTICAL);
	navigation_sizer = new wxBoxSizer(wxVERTICAL);
	empty_sizer = new wxBoxSizer(wxVERTICAL);
	option_sizer = new wxBoxSizer(wxVERTICAL);
	file_sizer = new wxBoxSizer(wxVERTICAL);

	//buttons that go on the top and are related to navigation
	go_to_chatbot = new wxButton(this, BUTTON_CHATBOT, _T("  Chatbot"), wxPoint(0, 0), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	go_to_about_us = new wxButton(this, BUTTON_ABOUT_US, _T("  About Us"), wxPoint(0, 30), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	
	//buttons that go on the bottom and involve the bot
	search = new wxButton(this, BUTTON_SEARCH, _T(" Search"), wxPoint(0, 60), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	open_file = new wxButton(this, BUTTON_OPEN_FILE, _T(" Open File"), wxPoint(0, 90), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	feeling_lucky = new wxButton(this, BUTTON_FEELING_LUCKY, _T(" Feeling Lucky"), wxPoint(0, 120), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	recommended = new wxButton(this, BUTTON_RECOMMENDED, _T(" Recommended Q&A"), wxPoint(0, 180), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);
	test_knowlodge = new wxButton(this, BUTTON_TEST_KNOWLEDGE, _T(" Test Your knowloedge"), wxPoint(0, 210), wxSize(300, 30), wxBU_LEFT | wxBORDER_NONE);

	//buttons that go on the bottom and are required by the open file function
	open_file1 = new wxButton(this, BUTTON_OPEN1, _T("Open file 1: "), wxDefaultPosition, wxDefaultSize, wxBU_LEFT | wxBORDER_NONE);
	open_file2 = new wxButton(this, BUTTON_OPEN2, _T("Open file 2: "), wxDefaultPosition, wxDefaultSize, wxBU_LEFT | wxBORDER_NONE);
	open_file3 = new wxButton(this, BUTTON_OPEN3, _T("Open file 3: "), wxDefaultPosition, wxDefaultSize, wxBU_LEFT | wxBORDER_NONE);
	open_file4 = new wxButton(this, BUTTON_OPEN4, _T("Open file 4: "), wxDefaultPosition, wxDefaultSize, wxBU_LEFT | wxBORDER_NONE);
	cancel = new wxButton(this, BUTTON_CANCEL, _T("Cancel action"), wxDefaultPosition, wxDefaultSize, wxBU_LEFT | wxBORDER_NONE);

	go_to_chatbot->SetBackgroundColour(wxColour(*wxWHITE));
	go_to_about_us->SetBackgroundColour(wxColour(*wxWHITE));
	
	navigation_sizer->Add(go_to_chatbot, 1, wxEXPAND | wxALL, 3);
	navigation_sizer->Add(go_to_about_us, 1, wxEXPAND | wxALL, 3);

	empty_sizer->AddSpacer(1);

	option_sizer->Add(search, 1, wxEXPAND | wxALL, 3);
	option_sizer->Add(open_file, 1, wxEXPAND | wxALL, 3);
	option_sizer->Add(feeling_lucky, 1, wxEXPAND | wxALL, 3);
	option_sizer->Add(recommended, 1, wxEXPAND | wxALL, 3);
	option_sizer->Add(test_knowlodge, 1, wxEXPAND | wxALL, 3);

	file_sizer->Add(open_file1, 1, wxEXPAND | wxALL, 3);
	file_sizer->Add(open_file2, 1, wxEXPAND | wxALL, 3);
	file_sizer->Add(open_file3, 1, wxEXPAND | wxALL, 3);
	file_sizer->Add(open_file4, 1, wxEXPAND | wxALL, 3);
	file_sizer->Add(cancel, 1, wxEXPAND | wxALL, 3);

	main_sizer->Add(navigation_sizer, 1, wxEXPAND | wxALL, 3);
	main_sizer->Add(empty_sizer, 3, wxEXPAND | wxALL, 3);
	main_sizer->Add(option_sizer, 3, wxEXPAND | wxALL, 3);
	main_sizer->Add(file_sizer, 3, wxEXPAND | wxALL, 3);

	main_sizer->Hide(file_sizer);
	main_sizer->Layout();
	this->SetSizer(main_sizer);

	Bind(wxEVT_BUTTON, &MenuPanel::hideOptionPanel, this, BUTTON_OPEN_FILE);
	Bind(wxEVT_BUTTON, &MenuPanel::hideFilePanel, this, BUTTON_OPEN1);
	Bind(wxEVT_BUTTON, &MenuPanel::hideFilePanel, this, BUTTON_OPEN2);
	Bind(wxEVT_BUTTON, &MenuPanel::hideFilePanel, this, BUTTON_OPEN3);
	Bind(wxEVT_BUTTON, &MenuPanel::hideFilePanel, this, BUTTON_OPEN4);
	Bind(wxEVT_BUTTON, &MenuPanel::hideFilePanel, this, BUTTON_CANCEL);

	Bind(wxEVT_BUTTON, &MenuPanel::openFile1, this, BUTTON_OPEN1);
	Bind(wxEVT_BUTTON, &MenuPanel::openFile2, this, BUTTON_OPEN2);
	Bind(wxEVT_BUTTON, &MenuPanel::openFile3, this, BUTTON_OPEN3);
	Bind(wxEVT_BUTTON, &MenuPanel::openFile4, this, BUTTON_OPEN4);
}

void MenuPanel::hideOptionPanel(wxCommandEvent& event)
{
	main_sizer->Hide(option_sizer);
	main_sizer->Show(file_sizer);
	main_sizer->Layout();
}

void MenuPanel::hideFilePanel(wxCommandEvent& event)
{
	main_sizer->Hide(file_sizer);
	main_sizer->Show(option_sizer);
	main_sizer->Layout();
}

void MenuPanel::openFile1(wxCommandEvent& event)
{
	//i know that declaring 4 functions with only one character differnt isn't nice
	//you cannot use any kind of array in Bind
	//these command functions only take one parameter

	OpenPDF op;
	try
	{
		op.openPDF("1");
	}
	catch (int err)
	{
		std::cout << err;
	}
}

void MenuPanel::openFile2(wxCommandEvent& event)
{
	OpenPDF op;
	try
	{
		op.openPDF("2");
	}
	catch (int err)
	{
		std::cout << err;
	}
}

void MenuPanel::openFile3(wxCommandEvent& event)
{
	OpenPDF op;
	try
	{
		op.openPDF("3_1");
	}
	catch (int err)
	{
		std::cout << err;
	}
}

void MenuPanel::openFile4(wxCommandEvent& event)
{
	OpenPDF op;
	try
	{
		op.openPDF("4");
	}
	catch (int err)
	{
		std::cout << err;
	}
}
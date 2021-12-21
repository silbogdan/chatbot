#include "MenuPanel.h"

MenuPanel::MenuPanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	go_to_chatbot = new wxButton(this, BUTTON_CHATBOT, _T("Chatbot"), wxPoint(0, 0), wxSize(150, 30), wxBU_LEFT);
	go_to_about_us = new wxButton(this, BUTTON_ABOUT_US, _T("About Us"), wxPoint(0, 30), wxSize(150, 30), wxBU_LEFT);

	/*vbox = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(vbox);
	vbox->Add(go_to_home, 1,wxSHAPED | wxFIXED_MINSIZE, 5);
	vbox->Add(go_to_chatbot, 1, wxSHAPED | wxFIXED_MINSIZE, 5);
	vbox->Add(go_to_about_us, 1, wxSHAPED | wxFIXED_MINSIZE, 5);*/
}
#include "MenuPanel.h"

MenuPanel::MenuPanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	go_to_home = new wxButton(this, BUTTON_HOME, _T("Home"), wxPoint(0, 0), wxSize(150, 30), wxBU_LEFT);
	go_to_chatbot = new wxButton(this, BUTTON_CHATBOT, _T("Chatbot"), wxPoint(0, 30), wxSize(150, 30), wxBU_LEFT);
}
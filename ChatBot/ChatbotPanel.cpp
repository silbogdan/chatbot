#include "ChatbotPanel.h"
#include <wx/string.h>
#include <wx/position.h>

ChatbotPanel* ceva;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	
	m_text = new wxStaticText(this, -1, wxT("This is the Chatbot panel!"), wxPoint(0, 0));
	
	wxTextCtrl* TextCtrl2 = new wxTextCtrl(this, wxID_ANY, _("Type a message..."), wxPoint(0, 580), wxSize(300, 20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	//TextCtrl2.getValue()
	send_button = new wxButton(this, BUTTON_SEND, _T("Send"), wxPoint(300, 580), wxSize(100, 21), wxBU_LEFT);
	ceva = this;
	
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	
}
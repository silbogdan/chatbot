#include "ChatbotPanel.h"
#include <wx/string.h>
#include <wx/position.h>
#include <sstream>

int i{};

wxTextCtrl* ChatbotPanel::TextCtrl2 = NULL;
wxListBox* ChatbotPanel::main_chat = NULL;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	m_text = new wxStaticText(this, -1, wxT("This is the Chatbot panel!"), wxPoint(0, 0));
	TextCtrl2 = new wxTextCtrl(this, wxID_ANY, _("Type a message..."), wxPoint(0, 580), wxSize(300, 20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	send_button = new wxButton(this, BUTTON_SEND, _T("Send"), wxPoint(300, 580), wxSize(100, 21), wxBU_LEFT);
	main_chat = new wxListBox(this, wxID_ANY, wxPoint(100, 100), wxSize(200, 200));
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	wxString a = TextCtrl2->GetValue(); //works well
	auto temp =  main_chat->Insert(a, i); //to insert items
	i++;
	//
	/* things to display pointers
	auto chaine2 = temp;
	std::stringstream tmpss;
	tmpss << chaine2;
	auto hhh = new wxStaticText(this, -1, tmpss.str(), wxPoint(250, 250));
	*/
	
}
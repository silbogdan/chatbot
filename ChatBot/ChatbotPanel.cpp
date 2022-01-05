#include "ChatbotPanel.h"
#include <wx/string.h>
#include <wx/position.h>
#include <sstream>

int i{};

wxTextCtrl* ChatbotPanel::TextCtrl2 = NULL;
wxListCtrl* ChatbotPanel::main_chat = NULL;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	TextCtrl2 = new wxTextCtrl(this, wxID_ANY, _("Type a message..."), wxPoint(0, 580), wxSize(300, 20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	send_button = new wxButton(this, BUTTON_SEND, _T("Send"), wxPoint(300, 580), wxSize(100, 21));
	main_chat = new wxListCtrl(this, wxID_ANY, wxPoint(100, 100), wxSize(200, 200), wxLC_REPORT);
	main_chat->InsertColumn(0, wxT("chatbot"));
	main_chat->InsertColumn(1, wxT("person"));
	//main_chat->SetColumnWidth(0, 100);
	//main_chat->SetColumnWidth(1, 100);

	big_sizer = new wxBoxSizer(wxVERTICAL);
	small_sizer = new wxBoxSizer(wxHORIZONTAL);
	small_sizer->Add(TextCtrl2, 9, wxEXPAND | wxALL, 5);
	small_sizer->Add(send_button, 1, wxEXPAND | wxALL, 5);
	big_sizer->Add(main_chat, 9, wxEXPAND | wxALL, 5);
	big_sizer->Add(small_sizer, 1, wxEXPAND | wxALL, 5);
	this->SetSizer(big_sizer);
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* temp;
	temp = new Message();
	temp->msg = TextCtrl2->GetValue();
	temp->isbot = 0;
	//wxString a = TextCtrl2->GetValue();//works well
	//auto temp =  main_chat->Insert(a, i); //to insert items

	//0 for bot/left, 1 for user/right
	main_chat->InsertItem(i, _(""));
	main_chat->SetItem(i, !temp->isbot, temp->msg);
	i++;

	/*wxListItem* item = new wxListItem();
	item->SetText(a);
	item->SetColumn(1);
	item->SetId(i);
	main_chat->InsertItem(*item);
	i++;*/


	/* things to display pointers
	auto chaine2 = temp;
	std::stringstream tmpss;
	tmpss << chaine2;
	auto hhh = new wxStaticText(this, -1, tmpss.str(), wxPoint(250, 250));
	*/
	
}
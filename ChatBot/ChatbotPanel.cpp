#include "ChatbotPanel.h"


int i{};

wxTextCtrl* ChatbotPanel::text_box = NULL;
wxListCtrl* ChatbotPanel::main_chat = NULL;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	text_box = new wxTextCtrl(this, wxID_ANY, _("Type a message..."), wxPoint(0, 580), wxSize(300, 20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	send_button = new wxButton(this, BUTTON_SEND, _T("Send"), wxPoint(300, 580), wxSize(100, 21));
	main_chat = new wxListCtrl(this, wxID_ANY, wxPoint(100, 100), wxSize(200, 200), wxLC_REPORT);

	main_chat->InsertColumn(0, wxT("chatbot"));
	main_chat->InsertColumn(1, wxT("person"));

	big_sizer = new wxBoxSizer(wxVERTICAL);
	small_sizer = new wxBoxSizer(wxHORIZONTAL);

	small_sizer->Add(text_box, 9, wxEXPAND | wxALL, 5);
	small_sizer->Add(send_button, 1, wxEXPAND | wxALL, 5);

	big_sizer->Add(main_chat, 9, wxEXPAND | wxALL, 5);
	big_sizer->Add(small_sizer, 1, wxEXPAND | wxALL, 5);

	this->SetSizer(big_sizer);
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* temp;
	temp = new Message();

	temp->msg = text_box->GetValue();
	temp->isbot = 0;
	
	main_chat->InsertItem(i, _(""));
	main_chat->SetItem(i, !temp->isbot, temp->msg);
	i++;
	text_box->ChangeValue("");
}
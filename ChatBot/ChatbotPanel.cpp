#include "ChatbotPanel.h"

int i{};
wxTextCtrl* ChatbotPanel::text_box = NULL;
wxListCtrl* ChatbotPanel::main_chat = NULL;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	wxBitmap* bitmap = new wxBitmap;
	text_box = new wxTextCtrl(this, wxID_HIGHEST + 10, _("Type a message..."), wxPoint(0, 580), wxSize(300, 20), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	bitmap->LoadFile("send.png", wxBITMAP_TYPE_PNG);
	send_button = new wxBitmapButton(this, BUTTON_SEND, *bitmap, wxPoint(300, 580), wxSize(10, 10), wxBORDER_NONE);
	main_chat = new wxListCtrl(this, wxID_ANY, wxPoint(100, 100), wxSize(200, 200), wxLC_REPORT | wxLC_VRULES);

	send_button->SetBackgroundColour(wxColour(*wxWHITE));

	main_chat->InsertColumn(0, _("chatbot"));
	main_chat->InsertColumn(1, _("person"));

	big_sizer = new wxBoxSizer(wxVERTICAL);
	small_sizer = new wxBoxSizer(wxHORIZONTAL);

	small_sizer->Add(text_box, 9, wxEXPAND | wxALL, 3);
	small_sizer->Add(send_button, 1, wxEXPAND | wxALL, 3);

	big_sizer->Add(main_chat, 9, wxEXPAND | wxALL, 3);
	big_sizer->Add(small_sizer, 1, wxEXPAND | wxALL, 3);

	this->SetSizer(big_sizer);

	delete bitmap;
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* temp;
	temp = new Message();

	temp->msg = text_box->GetValue();
	if (temp->msg == "") {
		delete temp;
		return;
	}
	temp->isbot = 0;
	
	main_chat->InsertItem(i, _(""));
	main_chat->SetItem(i, !temp->isbot, temp->msg);
	i++;
	text_box->ChangeValue("");

	delete temp;
}
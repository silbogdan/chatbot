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

	main_chat->InsertColumn(0, _(""));
	main_chat->InsertColumn(1, _(""), wxLIST_FORMAT_RIGHT);

	big_sizer = new wxBoxSizer(wxVERTICAL);
	small_sizer = new wxBoxSizer(wxHORIZONTAL);

	small_sizer->Add(text_box, 9, wxEXPAND | wxALL, 3);
	small_sizer->Add(send_button, 1, wxEXPAND | wxALL, 3);

	big_sizer->Add(main_chat, 9, wxEXPAND | wxALL, 3);
	big_sizer->Add(small_sizer, 1, wxEXPAND | wxALL, 3);

	this->SetSizer(big_sizer);
	
	main_chat->Bind(wxEVT_SIZE, &ChatbotPanel::Resize, this);

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

void ChatbotPanel::Resize(wxSizeEvent& event)
{
	auto size = main_chat->GetSize();
	auto w = size.GetWidth();

	main_chat->SetColumnWidth(0, w / 2);
	main_chat->SetColumnWidth(1, w / 2);
}

void ChatbotPanel::search_topic(wxCommandEvent& event)
{
	Message* message;
	message = new Message();
	message->msg =_("What are you searching?");

	main_chat->InsertItem(i, _(""));
	main_chat->SetItem(i, !message->isbot, message->msg);
	i++;
	text_box->ChangeValue("");

	delete message;
}

void ChatbotPanel::open_file(wxCommandEvent& event)
{
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

void ChatbotPanel::feeling_lucky(wxCommandEvent& event)
{
	wxMessageDialog* dial = new wxMessageDialog(NULL,
		wxT("Download completed\nsomething"), wxT("Info"), wxOK);
	dial->ShowModal();

	delete dial;
}

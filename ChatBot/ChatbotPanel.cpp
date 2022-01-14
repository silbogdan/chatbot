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

void ChatbotPanel::pushMessage(Message* x)
{
	if (x->msg == "") {
		return;
	}
	main_chat->InsertItem(i, _(""));
	main_chat->SetItem(i, !x->isbot, x->msg);
	i++;
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* temp;
	temp = new Message();

	temp->msg = text_box->GetValue();
	temp->isbot = 0;
	this->pushMessage(temp);
	
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

}

void ChatbotPanel::feeling_lucky(wxCommandEvent& event)
{
	wxMessageDialog* dial = new wxMessageDialog(NULL,
		wxT("Let me tell you something!"), wxT("Feeling lucky"), wxOK);
	dial->ShowModal();

	delete dial;
}

void ChatbotPanel::recommended(wxCommandEvent& event)
{
	Message* question, *answer;
	question = new Message();
	answer = new Message();

	question->msg = _("How is the weather in Bucharest?");
	question->isbot = false;
	this->pushMessage(question);

	answer->msg = _("It's raining");
	answer->isbot = true;
	this->pushMessage(answer);

	delete question;
	delete answer;
}

void ChatbotPanel::test_knowledge(wxCommandEvent& event)
{
	wxString b[] = { "A", "B", "C", "D" };

	wxMultiChoiceDialog* dial = new wxMultiChoiceDialog(NULL,
		_T("ceva"), _T("altceva"),4,  b, wxCHOICEDLG_STYLE, 
		wxDefaultPosition);
	dial->ShowModal();
	delete dial;
}

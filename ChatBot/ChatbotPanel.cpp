#include "ChatbotPanel.h"

int i{};
bool ChatbotPanel::is_waiting_for_search = false;
wxTextCtrl* ChatbotPanel::text_box = NULL;
wxListCtrl* ChatbotPanel::main_chat = NULL;
const wxFont* ChatbotPanel::custom_font;

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{	
	custom_font = new wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);
	wxBitmap* bitmap = new wxBitmap;

	text_box = new wxTextCtrl(this, wxID_HIGHEST + 10, _(""), wxPoint(0, 580), wxSize(300, 20), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	text_box->SetFont(*custom_font);
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
	main_chat->SetItemFont(i, *custom_font);
	i++;
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* keyword, * answer;
	keyword = new Message();
	answer = new Message();

	keyword->msg = text_box->GetValue();
	keyword->isbot = 0;
	this->pushMessage(keyword);

	if (ChatbotPanel::getSearchStatus())
	{
		getSearchResult(keyword, answer);
		this->pushMessage(answer);
		ChatbotPanel::deactivateSearch();
	}
	
	text_box->ChangeValue("");

	delete keyword;
	delete answer;
}

void ChatbotPanel::Resize(wxSizeEvent& event)
{
	auto size = main_chat->GetSize();
	auto w = size.GetWidth();

	main_chat->SetColumnWidth(0, w / 2);
	main_chat->SetColumnWidth(1, w / 2);
}

void ChatbotPanel::searchTopic(wxCommandEvent& event)
{
	Message* incentive;
	incentive = new Message;

	incentive->msg = _("What would you like to know?");
	incentive->isbot = 1;
	this->pushMessage(incentive);

	ChatbotPanel::activateSearch();
	delete incentive;
}

void ChatbotPanel::feelingLucky(wxCommandEvent& event)
{
	Message* gospel = new Message;

	getFactForFeelingLucky(gospel);

	wxMessageDialog* dial = new wxMessageDialog(NULL,
		gospel->msg, wxT("Feeling lucky"), wxOK);
	dial->ShowModal();

	delete dial;
	delete gospel;
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

void ChatbotPanel::testKnowledge(wxCommandEvent& event)
{
	wxString b[] = { "A", "B", "C", "D" };

	wxMultiChoiceDialog* dial = new wxMultiChoiceDialog(NULL,
		_T("ceva"), _T("altceva"),4,  b, wxCHOICEDLG_STYLE, 
		wxDefaultPosition);
	dial->ShowModal();
	delete dial;
}

ChatbotPanel::~ChatbotPanel()
{
	delete custom_font;
}

void getSearchResult(Message* q, Message* a)
{
	a->msg = _("I do not know anything about ") + q->msg + _(".");
	a->isbot = true;
}

void getFactForFeelingLucky(Message* f)
{
	f->msg = _("Bioprocesses are a mistery even for me!");
	f->isbot = true;
}

void getQandAForRecommended(wxString* q, wxString* a)
{
	wxString temp_q = _("What is the most important bioprocess?");
	wxString temp_a = _("As if I know!");
	
	q = &temp_q;
	a = &temp_a;
}
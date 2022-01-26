#include "ChatbotPanel.h"

int i{};
bool ChatbotPanel::is_waiting_for_search = false;
bool ChatbotPanel::is_waiting_for_choice = false;
Message ChatbotPanel::recommended_questions[4];
Message ChatbotPanel::recommended_answers[4];
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
	int lenght;
	const unsigned int max_lenght = 45;
	std::string same;
	std::string same_temp_substring;

	if (x->msg == "") {
		return;
	}

	same = x->msg.ToStdString();
	lenght = same.length();

	for (int k{}; k < lenght; )
	{
		if (k + max_lenght < lenght || (same.substr(k, max_lenght)).find_first_of('?') != -1)
		{
			//create a string thah has the maximum amount of characters before a space
			same_temp_substring = same.substr(k, max_lenght);
			auto temp = same_temp_substring.find_last_of(' ');
			auto x = same_temp_substring.find_first_of('?');
			if (x != -1)
				temp = x+1;
			same_temp_substring = same.substr(k, temp);
			k += temp;
		}
		else
		{
			same_temp_substring = same.substr(k, lenght - k + 1);
			k = lenght + 1;
		}
		
		wxString buffer(same_temp_substring);

		//show buffer

		main_chat->InsertItem(i, _(""));
		main_chat->SetItem(i, !x->isbot, buffer);
		main_chat->SetItemFont(i, *custom_font);
		i++;
	}
	return;
}

void ChatbotPanel::takeMessage(wxCommandEvent& event)
{	 
	Message* keyword, * answer;

	int j{};

	keyword = new Message();
	answer = new Message();

	keyword->msg = text_box->GetValue();
	keyword->isbot = 0;
	this->pushMessage(keyword);

	getSearchResult(keyword, answer);
	this->pushMessage(answer);
	ChatbotPanel::deactivateSearch();
	
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

	/*std::pair<Message*, Message*> retValues = getQandAForRecommended("Intrebare", "Raspuns");
	this->pushMessage(retValues.first);
	this->pushMessage(retValues.second);*/

	Message* recommendedMessage = new Message();
	recommendedMessage->msg =
		"Try asking these questions:\
	What is the purpose of bioprocess study?\
	What are the bioprocess modes of operation?\
	What is important for developing a general kinetic model?\
	What is cellulase?\
	What is the purpose of a fuzzy control system?";
	recommendedMessage->isbot = true;

	this->pushMessage(recommendedMessage);
}

void ChatbotPanel::testKnowledge(wxCommandEvent& event)
{
	Message* statement, *feedback;
	wxMessageDialog* dial;
	bool is_right;
	const wxMessageDialog::ButtonLabel a(_("False"));
	const wxMessageDialog::ButtonLabel b(_("True"));

	statement = new Message;
	feedback = new Message;

	getStatementForTest(statement, &is_right);

	dial = new wxMessageDialog(NULL, statement->msg, _("Test incoming!"),
		wxOK | wxCANCEL);
	dial->SetOKCancelLabels(a, b);

	//ok is false
	//cancel is true

	feedback->isbot = true;

	if (is_right)
	{
		auto x = dial->ShowModal();
		if (x == wxID_CANCEL)
		{
			feedback->msg = _("Congratulations! You were right!");
		}
		else
		{
			feedback->msg = _("You were wrong! Maybe next time!");
		}
	}
	else
	{
		auto x = dial->ShowModal();
		if (x == wxID_OK)
		{
			feedback->msg = _("Congratulations! You were right!");
		}
		else
		{
			feedback->msg = _("You were wrong! Maybe next time!");
		}
	}

	this->pushMessage(feedback);

	delete statement;
	delete feedback;
	delete dial;
}

ChatbotPanel::~ChatbotPanel()
{
	delete custom_font;
}

void getSearchResult(Message* q, Message* a)
{
	a->isbot = true;

	if (q->msg == "What is the purpose of bioprocess study?")
	{
		a->msg = _("The bioprocess study makes evident the principles that are the foundation of living systems. In the\
			first part of this chapter, different kind of bioprocesses(specially the aerobic bioprocesses) will\
			be analyzed, together with the most interesting parameters and a general overview on the cell\
			metabolism.In the second part, the most usual bioreactor types with some particularities will be\
			shown.Finally, a general overview on the bioprocess measuring systems will be presented in\
			addition with the information  organization  modalities and other some consonant possibilities on\
			these.\
			Find out more about this in PART ONE.");
	}
	else if (q->msg == "What are the bioprocess modes of operation?")
	{
		a->msg = _("From a technological point of view (Chisti, 1989, Tolbert et al. 1982) there are three main\
			bioprocess modes of operation:\
		-  Batch cultivation;\
		-  Fed - batch cultivation;\
		-  Continuous cultivation\
		Find out more about this in PART TWO.");
	}
	else if (q->msg == "What is important for developing a general kinetic model?")
	{
		a->msg = _("One of the most important objectives for developing a general kinetic model is to establish a\
			conceptual basis for microorganism growth description\n\
			Find out more about this in PART TWO.");
	}
	else if (q->msg == "What is cellulase?")
	{
		a->msg = _("Cellulase is a multicomponent enzymatic system, which comprises three main enzymes: endoglucanases,\
			exoglucanases(cellobiohydrolases) and beta - glucosidases.The individual enzymes act\
			synergistic for the complete degradation of insoluble cellulose.The most important cellulolytic\
			fungus is Trichoderma reesei, but it is of interest to study other organisms, like Aspergillus sp.,\
			which is able to produce a wide range of extracellular enzymes growing on various substrates.\
			Find out more about this in PART THREE.");
	}
	else if (q->msg == "What is the purpose of a fuzzy control system?")
	{
		a->msg = _("The design of a fuzzy control system arises from organization necessity of the human expert\
			knowledge.The  decisional quintessence of the control system is determined  by the\
			transition from the information objective level to the subjective one(i.e.the information\
			version level) (Srinivas, Chidambaram, 1995).Thus, the interest is focussed on human expert\
			experience(outlined through fuzzy rules) rather than information algorithmic process(Jecu,\
			Caramihai, 1996).\
			Find out more about this in PART FOUR");
	}
	else
	{
		a->msg = _("I do not know anything about ") + q->msg + _(".");
	}
}

void getFactForFeelingLucky(Message* f)
{
	f->msg = _("Bioprocesses are a mistery even for me!");
	f->isbot = true;
}

void getQsAndAsForRecommended(Message q[], Message a[])
{
	for (int j {}; j < 4; j++)
	{
		q[j].msg = _("ceva");
		q[j].isbot = true;
		a[j].msg = _("altceva");
		a[j].isbot = true;
	}
}

void getStatementForTest(Message* x, bool* is_statement_true)
{
	x->msg = _("Hint: False is the right answer.");
	*is_statement_true = false;
}
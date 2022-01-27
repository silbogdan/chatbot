#include "ChatbotPanel.h"

int i{};
bool ChatbotPanel::is_waiting_for_search = false;
bool ChatbotPanel::is_waiting_for_choice = false;
Message ChatbotPanel::recommended_questions[4];
Message ChatbotPanel::recommended_answers[4];
wxTextCtrl* ChatbotPanel::text_box = NULL;
wxListCtrl* ChatbotPanel::main_chat = NULL;
const wxFont* ChatbotPanel::custom_font;
const vector<int> parCounters = { 38, 97, 135, 190 };
const std::vector<std::string> luckyInfo =
{
	"The bioprocess study makes evident the principles that are the foundation of living systems. In the\
			first part of this chapter, different kind of bioprocesses(specially the aerobic bioprocesses) will\
			be analyzed, together with the most interesting parameters and a general overview on the cell\
			metabolism.In the second part, the most usual bioreactor types with some particularities will be\
			shown.Finally, a general overview on the bioprocess measuring systems will be presented in\
			addition with the information  organization  modalities and other some consonant possibilities on\
			these.\n\
			Find out more about this in PART ONE.",
		"From a technological point of view (Chisti, 1989, Tolbert et al. 1982) there are three main\
			bioprocess modes of operation:\n\
		-  Batch cultivation;\n\
		-  Fed-batch cultivation;\n\
		-  Continuous cultivation\n\
		Find out more about this in PART TWO.",
		"One of the most important objectives for developing a general kinetic model is to establish a\
			conceptual basis for microorganism growth description\n\
			Find out more about this in PART TWO.",
		"Cellulase is a multicomponent enzymatic system, which comprises three main enzymes: endoglucanases,\
			exoglucanases(cellobiohydrolases) and beta - glucosidases.The individual enzymes act\
			synergistic for the complete degradation of insoluble cellulose.The most important cellulolytic\
			fungus is Trichoderma reesei, but it is of interest to study other organisms, like Aspergillus sp.,\
			which is able to produce a wide range of extracellular enzymes growing on various substrates.\n\
			Find out more about this in PART THREE.",
		"The design of a fuzzy control system arises from organization necessity of the human expert\
			knowledge.The  decisional quintessence of the control system is determined  by the\
			transition from the information objective level to the subjective one(i.e.the information\
			version level) (Srinivas, Chidambaram, 1995).Thus, the interest is focussed on human expert\
			experience(outlined through fuzzy rules) rather than information algorithmic process(Jecu,\
			Caramihai, 1996).\n\
			Find out more about this in PART FOUR"
};

vector<string> fileNames = { "BioprocessInfo\\1.txt", "BioprocessInfo\\2.txt", "BioprocessInfo\\3_1.txt", "BioprocessInfo\\4.txt" };
TFIDFDatabase* ChatbotPanel::tfidfDatabase = new TFIDFDatabase(".\\tfidfmatrix.txt", ".\\dictionary.txt", fileNames);

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

	/* initialize random seed: */
	srand(time(NULL));
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
		if (k + max_lenght < lenght || (same.substr(k, max_lenght)).find_first_of('?') != -1 || (same.substr(k, max_lenght)).find_first_of(':') != -1)
		{
			//create a string thah has the maximum amount of characters before a space
			same_temp_substring = same.substr(k, max_lenght);
			auto temp = same_temp_substring.find_last_of(' ');
			auto x = same_temp_substring.find_first_of('?');
			if (x != -1)
				temp = x + 1;
			x = same_temp_substring.find_first_of(':');
			if (x != -1)
				temp = x + 1;
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
	What types of bioreactors are used?\
	What are the implementations for bioprocess control?\
	What means bioprocess intelligent control?\
	What is an expert system?\
	What is the main goal of the intelligent control structure?";
	recommendedMessage->isbot = true;

	this->pushMessage(recommendedMessage);
}

void ChatbotPanel::testKnowledge(wxCommandEvent& event)
{
	Message* statement, * feedback;
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

void ChatbotPanel::getSearchResult(Message* q, Message* a)
{
	a->isbot = true;
	//predefined Questiojns
	if (q->msg == "What types of bioreactors are used?")
	{
		a->msg = _("From this point if view two principal bioreactor types are now used in the bioprocessing operation (Moo-Young, 1985):\
					•	Stirrer reactor;\
					•	Pneumatic reactor.\
					Course 1, 1.2.2");
	}
	else if (q->msg == "What are the implementations for bioprocess control?")
	{
		a->msg = _(" The bioprocess control (and optimisation) strategies are based on three main implementations (Pokkinen et al., 1992):\
			•	Algorithmic optimisation : the optimum can be analytically reached(due to relationship defined between process parameters); hence, the algorithmic optimisation is cheaper that the adaptive one;\
		•	Adaptive optimisation : this kind of optimisation requires not a priori knowledge regarding the existing relationships between bioprocess parameters;\
		•	Intelligent technique optimisation : requires knowledge transfer from a human expert to the control structures(expert system, neural nets, fuzzy structure, etc).\
			Course 2, 2.2.1");
	}
	else if (q->msg == "What means bioprocess intelligent control?")
	{
		a->msg = _("The idea of an integrated control structure starts from the intelligent system, which is able to detect the bioprocess type,\
			 to design the process model and to control the fermentation process based on intelligent techniques, in order to maximize a performance index.");
	}
	else if (q->msg == "What is an expert system?")
	{
		a->msg = _("Structurally, the expert system is based on human expert knowledge, formalized as logical rules.\
				 The term “rules” has a large meaning. It includes different elements and knowledge corresponding to the bioprocess,\
				 i.e. the main process parameters, the general evolution curves, etc. The knowledge is configured as syntactical forms,\
				 if...then. Hence, after the rule selection by the expert system, the corresponding bioprocess control strategy (based on human knowledge)\
				is applied. Moreover, the expert system must supervise the whole control system, in order to change the global control strategy (if there is non-optimal)\
				 and even stop the bioprocess if the metabolic evolutions are troubled.");
	}
	else if (q->msg == "What is the main goal of the intelligent control structure?")
	{
		a->msg = _("The main goal of the intelligent control structure designed in this work is (cf. #3.3) to maximize\
				 the performance index through  pattern curve recognition and the applicability of a suitable fuzzy algorithm. The evolution type\
				 validation is build through  a large bioprocess type class, a priori imposed by a human expert.");
	}
	else
	{
		// Create an array with stemmed words of user's question
		vector<string> inputWords;
		stringstream ssin(q->msg.ToStdString());
		while (ssin.good())
		{
			string word;
			ssin >> word;
			if (word != "")
			{
				word = stemming::english_stem<>::get_stemmed_text(word);
				inputWords.push_back(word);
			}
		}

		// Get data from database
		vector<string> dictionary = ChatbotPanel::tfidfDatabase->getDictionary();
		vector<vector<double>> tfidfMatrix = ChatbotPanel::tfidfDatabase->getMatrix();
		vector<string> parArray = ChatbotPanel::tfidfDatabase->getParArray();
		int parCount = parArray.size();
		vector<double> sumsArray(parCount, 0.0);


		bool found = false;
		// Compare input words to dictionary
		for (string word : inputWords)
		{
			cout << word;

			// Create array of sums of word importance / frequency
			auto it = find(dictionary.begin(), dictionary.end(), word);
			if (it != dictionary.end())
			{
				found = true;
				int idx = it - dictionary.begin();
				for (int i = 0; i < parCount; i++)
				{
					sumsArray[i] += tfidfMatrix[i][idx];
				}
			}
		}

		// Create vector that maps paragraphs to document number
		vector<string> documentIndices;
		for (int i = 0; i < parArray.size(); i++)
		{
			if (i <= parCounters[0])
				documentIndices.push_back("ONE");
			else if (i <= parCounters[1])
				documentIndices.push_back("TWO");
			else if (i <= parCounters[2])
				documentIndices.push_back("THREE");
			else if (i <= parCounters[3])
				documentIndices.push_back("FOUR");
		}

		// Sort sumsArray in parallel with parArray and documentIndices
		for (int i = 0; i < sumsArray.size(); i++)
		{
			for (int j = i + 1; j < sumsArray.size(); j++)
			{
				if (sumsArray[i] < sumsArray[j])
				{
					double sumAux = sumsArray[i];
					string parAux = parArray[i];
					string docIdxAux = documentIndices[i];
					sumsArray[i] = sumsArray[j];
					parArray[i] = parArray[j];
					documentIndices[i] = documentIndices[j];
					sumsArray[j] = sumAux;
					parArray[j] = parAux;
					documentIndices[j] = docIdxAux;
				}
			}
		}

		string returnMessage = "";
		if (found)
		{
			string spaces = "                                                                  ";
			returnMessage.append("Here is what I found: " + spaces);
			for (int i = 0; i < 3; i++)
			{
				returnMessage.append(parArray[i] + " ");
				returnMessage.append("Find more information in document PART " + documentIndices[i] + spaces);
			}
		}
		else
		{
			returnMessage.append("I couldn't find anything related to " + q->msg);
		}

		a->msg = wxString::FromUTF8(returnMessage);
	}
}

void getFactForFeelingLucky(Message* f)
{
	/* generate secret number between 0 and 4: */
	int randNo = rand() % 5;
	f->msg = _(luckyInfo[randNo]);
	f->isbot = true;
}

void getQsAndAsForRecommended(Message q[], Message a[])
{
	for (int j{}; j < 4; j++)
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
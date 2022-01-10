#include "AboutUsPanel.h"

AboutUsPanel::AboutUsPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxT("The contributors of this Chatbot are:\n Silvasan Bogdan\n Macovei Radu-Marian\n Ionita Ionut \n Cretan Adrian \n Munteanu Rares"), wxPoint(0, 0));
	
	/*const wxString vect[] = {wxT("wbgwb"), wxT("ergvrewv")};
	wxListBox*  ceva = new wxListBox(this, wxID_ANY, wxPoint(200, 200), wxSize(300, 300));
	ceva->Insert(wxT("ejvhbkdj"), 0);
	ceva->Insert(*(vect + 1), 1);*/
}

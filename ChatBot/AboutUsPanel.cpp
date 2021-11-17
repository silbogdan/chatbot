#include "AboutUsPanel.h"

AboutUsPanel::AboutUsPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxT("The contributors of this Chatbot are:\n Silvasan Bogdan\n Macovei Radu-Marian\n Ionita Ionut \n Cretan Adrian \n Munteanu Rares"), wxPoint(0, 0));
}

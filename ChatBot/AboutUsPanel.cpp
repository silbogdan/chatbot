#include "AboutUsPanel.h"

AboutUsPanel::AboutUsPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxT("This is the AboutUs panel!"), wxPoint(0, 0));
}

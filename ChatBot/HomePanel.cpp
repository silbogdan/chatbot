#include "HomePanel.h"
#include "PDFReader.h"
#include "include/olestem/stemming/english_stem.h"

HomePanel::HomePanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxT("This is the Home panel!"), wxPoint(0, 0));

}
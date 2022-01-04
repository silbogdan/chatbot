#include "HomePanel.h"
#include "PDFReader.h"

HomePanel::HomePanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxString::FromUTF8("Hello from Home Page"), wxPoint(0, 0));
}
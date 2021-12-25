#include "HomePanel.h"
#include "PDFReader.h"

HomePanel::HomePanel(wxPanel* Parent)
	: wxPanel(Parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	PDFReader* pdf = new PDFReader("BioprocessInfo\\2.txt");
	std::string textToPrint = pdf->printText();

	m_text = new wxStaticText(this, -1, wxString::FromUTF8(textToPrint.substr(textToPrint.size() - 30)), wxPoint(0, 0));
}
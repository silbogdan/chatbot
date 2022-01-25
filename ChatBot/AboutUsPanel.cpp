#include "AboutUsPanel.h"

AboutUsPanel::AboutUsPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	master_sizer = new wxBoxSizer(wxVERTICAL);
	wxBitmap* bitmap = new wxBitmap;
	bitmap->LoadFile("ss.png", wxBITMAP_TYPE_PNG);

	display = new wxStaticBitmap(this, -1, *bitmap);
	master_sizer->Add(display, 1, wxEXPAND, 1);
	master_sizer->Layout();

	this->SetSizer(master_sizer);

	delete bitmap;
}

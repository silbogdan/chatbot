#include "ChatbotPanel.h"

ChatbotPanel::ChatbotPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_text = new wxStaticText(this, -1, wxT("This is the Chatbot panel!"), wxPoint(0, 0));
}
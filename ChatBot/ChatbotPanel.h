#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class ChatbotPanel : public wxPanel
{
public:
	ChatbotPanel(wxPanel* parent);

	wxStaticText* m_text;
};

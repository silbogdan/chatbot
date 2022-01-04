#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MenuPanel.h"

class AboutUsPanel : public wxPanel
{
public:
	AboutUsPanel(wxPanel* Parent);

	wxStaticText* m_text;
};


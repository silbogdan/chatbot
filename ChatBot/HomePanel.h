#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MenuPanel.h"

class HomePanel : public wxPanel
{
public:
	HomePanel(wxPanel* Parent);

	wxStaticText* m_text;
};

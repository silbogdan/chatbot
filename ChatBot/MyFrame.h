#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyApp.h"
#include "MenuPanel.h"
#include "ChatbotPanel.h"
#include "AboutUsPanel.h"

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    //~MyFrame();
    wxPanel* Parent;

    MenuPanel *mp;
    ChatbotPanel* cp;
    AboutUsPanel* ap;
    void ShowChatbot(wxCommandEvent& event);
    void ShowAboutUs(wxCommandEvent& event);

private:

    wxMenu* menuFile;
    wxMenu* menuHelp;
    wxMenuBar* menuBar;

    wxBoxSizer* hbox;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};

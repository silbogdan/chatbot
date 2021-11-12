#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyApp.h"
#include "MenuPanel.h"
#include "HomePanel.h"
#include "ChatbotPanel.h"
#include "AboutUsPanel.h"

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    //~MyFrame();
    wxPanel* Parent;

    MenuPanel *mp;
    HomePanel* hp;
    ChatbotPanel* cp;
    AboutUsPanel* ap;
    void ShowHome(wxCommandEvent& event);
    void ShowChatbot(wxCommandEvent& event);
  

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

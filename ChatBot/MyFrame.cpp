#include "MyFrame.h"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    menuFile = new wxMenu;
    menuHelp = new wxMenu;
    menuBar = new wxMenuBar;

    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to ChatBot!");

    Parent = new wxPanel(this, wxID_ANY);
    hbox = new wxBoxSizer(wxHORIZONTAL);

    mp = new MenuPanel(Parent);
    hp = new HomePanel(Parent);
    cp = new ChatbotPanel(Parent);
    ap = new AboutUsPanel(Parent);

    hbox->Add(mp, 1, wxEXPAND | wxALL, 5);
    hbox->Add(hp, 3, wxEXPAND | wxALL, 5);
    hbox->Add(cp, 3, wxEXPAND | wxALL, 5);
    hbox->Add(ap, 3, wxEXPAND | wxALL, 5);

    hbox->Hide(cp);
    hbox->Hide(ap);
    hbox->Layout();

    Parent->SetSizer(hbox);

    this->Centre();
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a bioprocesses ChatBot created as an University project",
        "About ChatBot", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::ShowHome(wxCommandEvent& event)
{
    hbox->Hide(cp);
    hbox->Layout();
    hp->Show(true);
    hbox->Layout();
}
void MyFrame::ShowChatbot(wxCommandEvent& event)
{
    hbox->Hide(hp);
    hbox->Layout();
    cp->Show(true);
    hbox->Layout();
}

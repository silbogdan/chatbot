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
    cp = new ChatbotPanel(Parent);
    ap = new AboutUsPanel(Parent);

    hbox->Add(mp, 1, wxEXPAND | wxALL | wxFIXED_MINSIZE, 5);
    hbox->Add(cp, 3, wxEXPAND | wxALL, 5);
    hbox->Add(ap, 3, wxEXPAND | wxALL, 5);

    //hbox->Hide(ap);
    hbox->Hide(cp);
    
    hbox->Layout();
    mp->main_sizer->Hide(mp->option_sizer);
    Parent->SetSizer(hbox);
    hbox->Fit(Parent);
    this->SetBackgroundColour(wxColour(*wxWHITE));

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


void MyFrame::ShowChatbot(wxCommandEvent& event)
{
    mp->main_sizer->Show(mp->option_sizer);
    mp->main_sizer->Hide(mp->file_sizer);
    mp->main_sizer->Layout();
    hbox->Hide(ap);
    hbox->Layout();
    cp->Show(true);
    hbox->Layout();
}

void MyFrame::ShowAboutUs(wxCommandEvent& event)
{
    mp->main_sizer->Hide(mp->option_sizer);
    mp->main_sizer->Hide(mp->file_sizer);
    mp->main_sizer->Layout();
    hbox->Hide(cp);
    hbox->Layout();
    ap->Show(true);
    hbox->Layout();
}
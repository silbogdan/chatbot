#include "MyApp.h"

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame* frame = new MyFrame("ChatBot", wxPoint(50, 50), wxSize(1024, 720));
    frame->SetMinSize(wxSize(1024, 720));
    frame->Show(true);
    frame->CentreOnScreen();
    return true;
}
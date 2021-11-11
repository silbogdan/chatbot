#include "MyApp.h"

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("ChatBot", wxPoint(50, 50), wxSize(1024, 720));
    frame->Show(true);
    frame->CentreOnScreen();
    return true;
}

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyApp.h"
#include "MyFrame.h"
#include "MenuPanel.h"
#include <wx/event.h>

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_BUTTON(BUTTON_CHATBOT, MyFrame::ShowChatbot)
EVT_BUTTON(BUTTON_ABOUT_US, MyFrame::ShowAboutUs)
EVT_BUTTON(BUTTON_SEND, ChatbotPanel::takeMessage)
EVT_TEXT_ENTER(wxID_HIGHEST + 10, ChatbotPanel::takeMessage)
//EVT_SIZE(ChatbotPanel::Resize)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);



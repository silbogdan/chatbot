// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".



/*
	The error:
		_wx64 can only be specified on int, long, and pointer types
	is caused by memory leaks:
		Dumping objects ->
		{9252} normal block at 0x000001A9DBD311E0, 128 bytes long.
		Data: <8S _            > 38 53 C2 5F F7 7F 00 00 00 00 00 00 00 00 00 00 
		Object dump complete.
	code still runs, but some fixes would be:
		1. deallocating the memory block
		2. using smart pointers instead of raw ones (advanced)
*/

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif



#include "MyApp.h"
#include "MyFrame.h"
#include "MenuPanel.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(BUTTON_HOME, MyFrame::OnExit)
EVT_MENU(BUTTON_CHATBOT, MyFrame::OnExit)
EVT_MENU(BUTTON_ABOUT_US, MyFrame::ShowChatbot)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);



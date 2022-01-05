#include "OpenPDF.h"

void OpenPDF::openPDF(string textPDF) 
{
	if (textPDF == "a")
		ShellExecute(GetDesktopWindow(), L"open", L"1.pdf", NULL, NULL, SW_SHOWNORMAL);
	if (textPDF == "b")
		ShellExecute(GetDesktopWindow(), L"open", L"2.pdf", NULL, NULL, SW_SHOWNORMAL);
	if (textPDF == "c")
		ShellExecute(GetDesktopWindow(), L"open", L"3_1.pdf", NULL, NULL, SW_SHOWNORMAL);
	if (textPDF == "d")
		ShellExecute(GetDesktopWindow(), L"open", L"4.pdf", NULL, NULL, SW_SHOWNORMAL);
}
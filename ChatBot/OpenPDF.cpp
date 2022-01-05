#include "OpenPDF.h"


void OpenPDF::openPDF(string textToPDF) {
	if (textToPDF == "a")
		ShellExecute(GetDesktopWindow(), L"open", L"PDF\\1.pdf", NULL, NULL, SW_SHOWNORMAL);
	if(textToPDF == "b")
		ShellExecute(GetDesktopWindow(), L"open", L"PDF\\2.pdf", NULL, NULL, SW_SHOWNORMAL);
	if (textToPDF == "c")
		ShellExecute(GetDesktopWindow(), L"open", L"PDF\\3_1.pdf", NULL, NULL, SW_SHOWNORMAL);
	if (textToPDF == "d")
		ShellExecute(GetDesktopWindow(), L"open", L"PDF\\4.pdf", NULL, NULL, SW_SHOWNORMAL);
}
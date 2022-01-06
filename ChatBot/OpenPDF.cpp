#include "OpenPDF.h"

void OpenPDF::openPDF(string textPDF) 
{
	textPDF.append(".pdf");
	std::wstring stemp = std::wstring(textPDF.begin(), textPDF.end());
	LPCWSTR convertedText = stemp.c_str();


	int nReturn = (int)ShellExecute(GetDesktopWindow(), L"open", convertedText, NULL, NULL, SW_SHOWNORMAL);
	if (nReturn < 32)
			throw 1;
}
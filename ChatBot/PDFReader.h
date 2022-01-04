#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class PDFReader
{
private:
	std::fstream file;

public:
	PDFReader(std::string filePath);
	std::string printText();
};


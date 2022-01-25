#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class PDFReader
{
private:
	std::fstream file;

public:
	PDFReader(std::string filePath);
	std::string printText();
	std::vector<std::string> getData();
};


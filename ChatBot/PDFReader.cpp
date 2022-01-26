#include "PDFReader.h"

PDFReader::PDFReader(std::string filePath)
{
	try
	{
		file.open(filePath, std::fstream::in);
		if (&file == nullptr)
			throw 1;
	}
	catch (int err)
	{
		if (err == 1)
		{
			std::cout << "File open error";
		}
		else
		{
			std::cout << "Unknown error";
		}
	}
}

std::string PDFReader::printText()
{
	if (&file == nullptr)
		std::cout << "No file was open";

	std::string text;
	std::string finalText;
	while (std::getline(file, text))
	{
		if (text != "")
		{
			finalText.append(text);
		}
	}

	return finalText;
}

std::vector<std::string> PDFReader::getData()
{
	if (&file == nullptr)
		std::cout << "No file was open";

	std::string text;
	std::string currText = "";
	std::vector<std::string> finalTextArray;
	while (std::getline(file, text))
	{
		if (text != "|")
		{
			currText.append(text);
			currText.append("\n");
		}
		else
		{
			finalTextArray.push_back(currText);
			currText = "";
		}
	}

	return finalTextArray;
}
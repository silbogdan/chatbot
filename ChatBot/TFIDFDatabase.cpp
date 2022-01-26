#include "TFIDFDatabase.h"

TFIDFDatabase::TFIDFDatabase(string matrixDatabase, string dictionaryDatabase, vector<string> fileNames)
{
	// Populate matrix
	fstream file;
	file.open(matrixDatabase.c_str(), fstream::in);
	
	string line;
	while (getline(file, line))
	{
		vector<double> row;
		stringstream ssin(line);
		while (ssin.good()) 
		{
			string strValue;
			ssin >> strValue;
			if (strValue != "")
				row.push_back(stod(strValue));
		}

		tfidfMatrix.push_back(row);
	}

	file.close();

	// Populate dictionary
	file.open(dictionaryDatabase.c_str(), fstream::in);

	while (getline(file, line))
	{
		dictionary.push_back(line);
	}

	file.close();

	// Populate parArray
	parArray = getParArrayFromFiles(fileNames);
}

vector<string> TFIDFDatabase::getParArrayFromFiles(vector<string> fileNames)
{
	std::fstream file;
	std::vector<std::string> finalTextArray;

	for (std::string fileName : fileNames)
	{
		file.open(fileName.c_str(), std::fstream::in);
		if (!file.is_open())
			exit;

		std::string text;
		std::string currText = "";
		while (std::getline(file, text))
		{
			if (text != "|")
			{
				currText.append(text);
			}
			else
			{
				finalTextArray.push_back(currText);
				currText = "";
			}
		}

		file.close();
	}


	return finalTextArray;
}

vector<string> TFIDFDatabase::getDictionary()
{
	return dictionary;
}

vector<string> TFIDFDatabase::getParArray()
{
	return parArray;
}

vector<vector<double>> TFIDFDatabase::getMatrix()
{
	return tfidfMatrix;
}
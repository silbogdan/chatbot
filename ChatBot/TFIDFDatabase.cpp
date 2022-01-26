#include "TFIDFDatabase.h"

TFIDFDatabase::TFIDFDatabase(string matrixDatabase, string dictionaryDatabase)
{
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
			row.push_back(stod(strValue));
		}

		tfidfMatrix.push_back(row);
	}

	file.close();
}
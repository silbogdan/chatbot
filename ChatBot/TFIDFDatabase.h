#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class TFIDFDatabase
{
private:
	vector<vector<double>> tfidfMatrix;
	vector<string> dictionary;

public:
	TFIDFDatabase(string matrixDatabase, string dictionaryDatabase);
	vector<vector<double>> getMatrix();
	vector<string> getDictionary();
};


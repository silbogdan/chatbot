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
	vector<string> parArray;

public:
	TFIDFDatabase(string matrixDatabase, string dictionaryDatabase, vector<string> fileNames);
	vector<string> getParArrayFromFiles(vector<string> fileNames);

	vector<vector<double>> getMatrix();
	vector<string> getDictionary();
	vector<string> getParArray();
};


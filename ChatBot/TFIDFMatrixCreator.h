#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/olestem/stemming/english_stem.h"

class TFIDFMatrixCreator
{
private:
    std::vector<std::vector<int>> freqMatrix;
    std::vector<std::string> dictionary;
    std::vector<std::vector<double>> TFIDFMatrix;
    std::vector<std::string> parArray;
    std::fstream file;


public:
    // Reads data from multiple files
    std::vector<std::string> getData(std::vector<std::string> files)
    {
        std::fstream file;
        std::vector<std::string> finalTextArray;

        for (std::string fileName : files)
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

    void init(std::string matrixFile)
    {
        // Create matrix
        std::string line;
        file.open(matrixFile.c_str(), std::fstream::in);

        while (std::getline(file, line))
        {
            if (line[0] != '|')
            {
                std::vector<int> counters;
                std::string space_delimiter = " ";
                size_t pos = 0;
                while ((pos = line.find(space_delimiter)) != std::string::npos)
                {
                    counters.push_back(std::stoi(line.substr(0, pos)));
                    line.erase(0, pos + space_delimiter.length());
                }

                freqMatrix.push_back(counters);
            }
        }

        file.close();

        // Create paragraph array
        parArray = getData({ "BioprocessInfo\\1.txt", "BioprocessInfo\\2.txt", "BioprocessInfo\\3_1.txt", "BioprocessInfo\\4.txt" });

        // Create dictionary
        file.open("dictionary.txt", std::fstream::in);

        std::vector<std::string> dictionary;
        while (std::getline(file, line))
        {
            dictionary.push_back(line);
        }

        file.close();
    }

    void createTFIDFMatrix(std::string outputFileName)
    {
        std::vector<int> wordAppearence;
        for (int j = 0; j < dictionary.size(); j++)
        {
            int counter = 0;
            for (int i = 0; i < freqMatrix.size(); i++)
            {
                if (freqMatrix[i][j] > 0)
                {
                    counter++;
                }
            }

            wordAppearence.push_back(counter);
        }

        // Calculate TF and IDF
        for (int i = 0; i < freqMatrix.size(); i++)
        {
            std::vector<double> TFIDFRow;
            for (int j = 0; j < freqMatrix[i].size(); j++)
            {
                double tf = (double)freqMatrix[i][j] / (double)parArray[i].size();
                double idf;
                if (wordAppearence[j] != 0)
                {
                    idf = std::log10((double)parArray.size() / (double)wordAppearence[j]);
                }
                else
                {
                    idf = 0;
                }

                TFIDFRow.push_back(tf * idf);
            }

            TFIDFMatrix.push_back(TFIDFRow);
        }

        // Write to file
        file.open(outputFileName.c_str(), std::fstream::out);

        for (std::vector<double> row : TFIDFMatrix)
        {
            for (double elem : row)
            {
                file << elem << " ";
            }

            file << "\n";
        }

        file.close();
    }
};


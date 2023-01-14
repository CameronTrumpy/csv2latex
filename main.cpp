// main.cpp
// Written by Cameron Trumpy https://github.com/CameronTrumpy
// This class reads a user inputted csv file, and translates it into a latex
// table. This utility was written for use in University of Michigan EECS 203.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "csv2latex.h"
#include "rapidcsv.h"

using namespace std;

int main() {
    initMap();
    string inputFile;
    cout << "Enter CSV filename...\n";
    cin >> inputFile;

    rapidcsv::Document doc(inputFile);
    ofstream outputFile(inputFile + "_latex.txt");
    // Write the latex table header to output file
    outputFile << "\\begin{displaymath} \\begin{array}{|";
    // Write the correct number of column spots to output file
    for (size_t i = 0; i < doc.GetColumnCount(); i++) {
        outputFile << " c |";
    }

    outputFile << "} \n\\hline\n";

    // Print column titles
    for (size_t i = 0; i < (doc.GetColumnCount() - 1); i++) {
        outputFile << parseHeaders(doc.GetColumnName(i)) << " & ";
    }
    outputFile << parseHeaders(doc.GetColumnName(doc.GetColumnCount() - 1));

    outputFile << "\\\\\n\\hline\n";

    for (size_t i = 0; i < (doc.GetRowCount()); i++) {
        for (size_t j = 0; j < (doc.GetColumnCount()); j++) {
            string cellText = doc.GetCell<string>(j, i);
            if (j != doc.GetColumnCount() - 1) {
                outputFile << cellText << " & ";
            } else {
                outputFile << cellText;
            }
        }
        outputFile << "\\\\\n";
    }
    outputFile << "\\hline\n\\end{array} \\end{displaymath}";

    outputFile.close();
    // cout << parseHeaders("(P AND Q) OR !P OR !Q");
}
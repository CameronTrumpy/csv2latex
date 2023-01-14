#include "csv2latex.h"

#include <map>
#include <string>
#include <vector>

using namespace std;
map<string, string> latexMap;

// try to init during compile-time instead of runtime?
void initMap() {
    latexMap.insert(make_pair("!", "\\neg "));
    latexMap.insert(make_pair("AND", "\\land"));
    latexMap.insert(make_pair("OR", "\\lor"));
    latexMap.insert(make_pair("IF", "\\rightarrow"));
    latexMap.insert(make_pair("IFF", "\\equiv"));
    latexMap.insert(make_pair(" ", " "));
    latexMap.insert(make_pair("(", "("));
    latexMap.insert(make_pair(")", ")"));
}

// read characters until space or parenthesis, convert that string from map,
string parseHeaders(string cellData) {
    string outputString;
    string workingString;
    for (size_t i = 0; i < cellData.length(); i++) {
        char curChar = cellData.at(i);
        if (curChar == ' ' || curChar == '(' || curChar == ')') {
            if (latexMap.find(workingString) == latexMap.end()) {
                outputString.append(workingString);
            } else {
                outputString.append(latexMap[workingString]);
            }
            outputString.push_back(curChar);
            workingString.clear();
        } else if (curChar == '!') {
            string s(1, curChar);
            outputString.append(latexMap[s]);
        } else {
            workingString.push_back(cellData.at(i));
        }
    }
    outputString.append(workingString);
    return outputString;
}

// char parseCells(char cellData) { return cellData; }
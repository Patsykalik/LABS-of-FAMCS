#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
bool iscomment( string& line) {
    int index = 0;
    while (index < line.length() && line[index]==' ') {
        index++;
    }
    if (line[index] == '/' and line[index + 1] == '/' and index + 1 < line.length()) return true;
    else return false;
}
string getcommenttext(string& line) {
    int index = 0;
    while (index < line.length() && line[index]==' ') {
        index++;
    }
    if (index + 1 < line.length() && line[index] == '/' && line[index + 1] == '/') {
        index += 2;
    }
    while (index < line.length() && line[index] == ' ') {
        index++;
    }
    return line.substr(index);
}
int main() {
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    if (!inputfile.is_open()) {
        cout << "Error:file is not open!" << endl;
        return 1;
    }
    if (!outputfile.is_open()) {
        cout << "Error:file is not open!" << endl;
        return 1;
    }
    vector<string> lines;
    string currentLine;
    while (getline(inputfile, currentLine)) {
        lines.push_back(currentLine);
    }
    int linenumber = 0;
    bool foundgroups = false;
    while (linenumber < lines.size()) {
        if (iscomment(lines[linenumber])) {
            string commentText = getcommenttext(lines[linenumber]);
            int groupStart = linenumber + 1;
            int repeatCount = 1;

            int nextLine = linenumber + 1;
            while (nextLine < lines.size() &&
                iscomment(lines[nextLine]) &&
                getcommenttext(lines[nextLine]) == commentText) {
                repeatCount++;
                nextLine++;
            }

            if (repeatCount >= 2) {
                foundgroups = true;
                outputfile << "text of comment: " << commentText << endl;
                outputfile << "repeat ñount: " << repeatCount << endl;
                outputfile << "from the " << groupStart <<" string" << endl;
                outputfile << endl << endl;
            }
            linenumber = nextLine;
        }
        else {
            linenumber++;
        }
    }
    if (!foundgroups) {
        outputfile << "has no groups!" << endl;
    }
    inputfile.close();
    outputfile.close();
    return 0;
}
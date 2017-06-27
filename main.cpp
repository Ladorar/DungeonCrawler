using namespace std;
#include <fstream>
#include <iostream>
#include <vector>

#include <cstdlib>

#include "GameEngine.h"

using namespace std;



void standart() {
    vector<string> data;
    vector<string> relation;
    data.push_back("##########");
    data.push_back("#........#");
    data.push_back("######X###");
    data.push_back("##?......#");
    data.push_back("#........#");
    data.push_back("#........#");
    data.push_back("#######..#");
    data.push_back("#........#");
    data.push_back("#........#");
    data.push_back("##########");
    relation.push_back("D26S32");
    relation.push_back("CC99C82");
    //relation.push_back("CM99C85");
    relation.push_back("GreatSword.81");
    relation.push_back("T18");
    relation.push_back("CN44A42");
    GameEngine ge(10, 10, data,relation);
    ge.run();
}

void loadFromFile() {
    int length;
    int width;
    string kawiesonst;
    bool breakpoint = false;
    vector<string> temp;
    vector<string> dataload;
    vector<string> relationload;
    fstream datei ("load.txt", ios::in);
    string line;
    while (breakpoint == false) {
            getline (datei, line);
            if (line == "endofmap") breakpoint = true;
            else dataload.push_back(line);   
    }
//    while (datei.good() == true || breakpoint == true) {      // Damit soll die größe vom Spielfeld bestimmt werden geht aber noch nich ganz
//        getline (datei, line);
//        if (line.at(0) == '.') breakpoint = false;
//        else {
//            length = static_cast<int> (line) - 48;
//        }
//    }
    while (datei.good() == true) {
        getline (datei, line);
        relationload.push_back(line);
    }
    datei.close();
    GameEngine ge(10, 10, dataload,relationload);
    ge.run();
}



int main() {
    int intput;
    cout << "<<<Hauptmenue>>>" << endl;
    cout << "1. Spiel mit Standarteinstellugen" << endl;
    cout << "2. Spielstand laden" << endl;
    cout << "3. Beenden" << endl;
    cin >> intput;
    switch (intput) {
    case 1: standart();
        break;
    case 2: loadFromFile();
        break;
    case 3: return 0; 
    }
}




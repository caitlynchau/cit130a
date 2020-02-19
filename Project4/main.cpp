//
//  main.cpp
//  Project4
//
//  Created by Caitlyn Chau on 7/24/19.
//  Copyright © 2019 Caitlyn Chau. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    char ch;
    
    //create inFile for reading and outFile for writing
    ifstream inFile;
    ofstream outFile;
    inFile.open("originalVersion.txt", ios::in);
    outFile.open("codedVersion.txt", ios::out);
    
    if (inFile){ //make sure inFile was successfully opened
        while (inFile >> ch){
            char plusFive = ch + 5; //add 5 to ASCII code
            outFile << plusFive; //write to outFile
        }
        inFile.close();
        outFile.close();
    }else{
        cout << "Error: could not open file\n";
    }
    
    return 0;
}

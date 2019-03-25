// ReadFromFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string inFilename = "text.txt";

	ifstream inFile;

	inFile.open(inFilename);

	if (inFile.is_open) {

		string line;

		while (inFile) {

			getline(inFile, line);
			cout << line << endl;
		}
		inFile.close();
	}

	else {
		cout << "ould not open file: " << inFilename << endl;
	}
	
    return 0;
}


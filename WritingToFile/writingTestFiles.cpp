// writing files

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {

	// output file stream and is used to create files and to write information to files
	ofstream outFile;

	string outputFileName = "text.txt";

	// open a file 
	outFile.open(outputFileName);

	//check wherther file is opened(created) or not
	if (outFile.is_open()) {
		outFile <<"Hello there" << endl;
		outFile <<"I am Engin Bozkurt" << endl;
		outFile.close();
	}
	else {
		cout << "Could not create a file." << outputFileName  << endl;
	}

    return 0;
}


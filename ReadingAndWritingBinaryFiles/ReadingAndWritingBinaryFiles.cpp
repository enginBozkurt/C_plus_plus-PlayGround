// ReadingAndWritingBinaryFiles.cpp 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//when working with hardware devices where you need to ensure that the compiler does not insert padding into the data 
//and each member follows the previous one (remove padding)
#pragma pack(push, 1)

struct Person {
	char name[50];
	int age;
	double height;
};

#pragma pack(pop)


int main() {

	Person someone = {"Frodo", 220, 0.8};

	string fileName = "test.bin";

	ofstream outputFile;

	outputFile.open(fileName, ios::binary);


	////// Write binary file ///////

	if (outputFile.is_open()) {

		//The next line is how you write most types:  cast a pointer to a type to a char * and give sizeof the type
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}
	else {
		cout << "Could not create file " + fileName;
	}

	////// Read binary file ///////
	Person someoneElse = {};

	ifstream inputFile;

	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {

		//The next line is how you read most types:  cast a pointer to a type to a char * and give sizeof the type
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	}
	else {
		cout << "Could not read file " + fileName << endl;
	}

	cout << someoneElse.name << " , " << someoneElse.age << " , " << someoneElse.height <<endl;


    return 0;
}


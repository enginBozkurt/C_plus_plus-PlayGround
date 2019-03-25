// ReverseString.cpp
//

#include "pch.h"
#include <iostream>

int main()
{
	char text[] = "Engin";

	int nChars = sizeof(text) - 1;

	char *pStart = text;
	char *pEnd = text + nChars - 1;

	while (pStart < pEnd) {
		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart++;
		pEnd--;
	}

    std::cout << text << std::endl;
}
// Character to ASCII Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char inputCharacter;
	bool repeat;
	repeat = true;
	while (repeat == true)
	{
		cout << "0 has a ASCII code of 48. Input a keyboard character: ";
		cin >> inputCharacter;
		if (inputCharacter == 48)
		{
			return 0;
		}
		cout << inputCharacter << " has ASCII code " << static_cast<int>(inputCharacter) << endl;
		cout << "Input 0 to exit." << endl;
	}
}
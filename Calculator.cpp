// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double Num1, Num2, Result, Type, PassType;
int Pass, SuperPass, Pass2, modulusNum1, modulusNum2;

void WhichType()
{
	if (Type == 1)
	{
		Result = Num1 + Num2;
	}
	if (Type == 2)
	{
		Result = Num1 - Num2;
	}
	if (Type == 3)
	{
		Result = Num1 * Num2;
	}
	if (Type == 5)
	{
		modulusNum1 = Num1;
		modulusNum2 = Num2;
		Result = modulusNum1 % modulusNum2;
	}
	if (Type == 4)
	{
		Result = Num1 / Num2;
	}
}

void Calculating()
{
	cout << "Type the first number: ";
	cin >> Num1;
	cout << endl;
	cout << "And the second number: ";
	cin >> Num2;
	cout << endl;
	WhichType();
	cout << "The result is: " << Result << endl << endl;
}

int main()
{
	Pass = 1;
	SuperPass = 1;
	Type = 0;
	while (SuperPass == 1)
	{
		while (Pass = 1)
		{
			Pass2 = 1;
			cout << "Type your desired Calculating Type \n";
			cout << "Addition --> 1 | Subtraction --> 2 | Multiplication --> 3 | Division --> 4 | Modulus --> 5 | Exit > 6 \n";
			cin >> Type;
			if (Type > 5)
			{
				return 0;
			}
			else if (Type == 0)
			{
				cout << "0 isn't an option. Type a new option. " << endl << endl;
			}
			else if (int (Type) != Type)
			{
				cout << "The options do not include decimals. " << endl << endl;
			}
			else if (Type < 6 && Type > 0)
			{
				Pass = 0;
				break;
			}
		}
		Calculating();
		while (Pass2 == 1)
		{
			cout << "Do you want to calculate again? " << endl;
			cout << "Yes --> 1 | No --> 2 \n";
			cin >> PassType;
			if (PassType > 2)
			{
				cout << "I meant 1 or 2, not more. \n";
			}
			else if (PassType == 0)
			{
				cout << "0 isn't an option. \n";
			}
			else if (int (PassType) != PassType)
			{
				cout << "The options do not include decimals. \n";
			}
			else if (PassType == 2)
			{
				return 0;
			}
			else if (PassType == 1)
			{
				Pass2 = 0;
				SuperPass = 1;
			}
		}
	}
}
/*
if (Num2 == 0)
{
cout << "Error, can't divide by 0. Type a new number. ";
cin >> Num2;
cout << endl;
}
*/
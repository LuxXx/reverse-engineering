#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>

// Author: LuxXx
// https://github.com/LuxXx

using namespace std;

long generateKey(string username) {

	long key = 0;
	long deadCode = 0xDEADC0DE;
	long tmp = 0;

	for (int i = 0; i < username.length(); i++)
	{
		tmp = 0x666 * (deadCode + username.at(i));
		deadCode += tmp;
	}
	key = tmp - 0x777;

	return key;
}

int main()
{

	cout << "Please enter your username: ";

	string name;
	getline(cin, name);
	
	char key[128];
	wsprintfA(key, "%u", generateKey(name));
	
	cout << "Key: " << key << '\n';
	getline(cin, name); // my system("pause")
}
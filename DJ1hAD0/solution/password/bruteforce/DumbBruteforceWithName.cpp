#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
// This is our alphabet we bruteforce with:
// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
const int FIRST_CHAR = 33;
const int LAST_CHAR = 126;
const int PASSWORD_SUM = 866;

// The upper bound of existing passwords is (126-33)^8 = 5595818096650401
// Exact number: number_of_solutions(sum i = 0 to 8 a_i = b), where a_i are element of {33, ..., 126}

using namespace std;
// I know this algorithm is not good, but I just wanted to try it to get me a huge load of passwords
// @param s: the ostream where the passwords a send to
// @param num_of_passwords_to_find: how many passwords should the algorithm brute force, -1 if you want to calculate as many as possible
// @param startsWith: a sequence which the password should start with
int bruteForce(ostream& s, long num_of_passwords_to_find, string startsWith) {
	if (startsWith.length() > 8) return 0;
	int found_passwords_count = 0;

	
	string chars = "12345678";

	for (int i = 0; i < chars.length(); i++)
	{
		chars[i] = (char) FIRST_CHAR;
	}
	for (int i = 0; i < startsWith.length(); i++)
	{
		chars[i] = startsWith.at(i);
	}

	for (int a = chars[0]; a <= LAST_CHAR; a++)
	{
		// no continue check necessary because 866-7*126 is -16, a will always be greater than -16
		if (chars[0] != FIRST_CHAR && a > chars[0]) continue;
		for (int b = chars[1]; b <= LAST_CHAR; b++)
		{
			if (chars[1] != FIRST_CHAR && b > chars[1]) continue;
			if (a + b < PASSWORD_SUM - 6 * LAST_CHAR) continue;
			for (int c = chars[2]; c <= LAST_CHAR; c++)
			{
				if (chars[2] != FIRST_CHAR && c > chars[2]) continue;
				if (a + b + c < PASSWORD_SUM - 5 * LAST_CHAR) continue;
				for (int d = chars[3]; d <= LAST_CHAR; d++)
				{
					if (chars[3] != FIRST_CHAR && d > chars[3]) continue;
					if (a + b + c + d < PASSWORD_SUM - 4 * LAST_CHAR) continue;
					for (int e = chars[4]; e <= LAST_CHAR; e++)
					{
						if (chars[4] != FIRST_CHAR && e > chars[4]) continue;
						if (a + b + c + d + e < PASSWORD_SUM - 3 * LAST_CHAR) continue;
						for (int f = chars[5]; f <= LAST_CHAR; f++)
						{
							if (chars[5] != FIRST_CHAR && f > chars[5]) continue;
							if (a + b + c + d + e + f < PASSWORD_SUM - 2 * LAST_CHAR) continue;
							for (int g = chars[6]; g <= LAST_CHAR; g++)
							{
								if (chars[6] != FIRST_CHAR && g > chars[6]) continue;
								if (a + b + c + d + e + f + g < PASSWORD_SUM - 1 * LAST_CHAR) continue;
								for (int h = chars[7]; h <= LAST_CHAR; h++)
								{
									if (chars[7] != FIRST_CHAR && h > chars[7]) continue;
									if (a + b + c + d + e + f + g + h == PASSWORD_SUM) {
										if (num_of_passwords_to_find != -1 && found_passwords_count >= num_of_passwords_to_find) return found_passwords_count;
										found_passwords_count++;
										s << (char)a << (char)b << (char)c << (char)d << (char)e << (char)f << (char)g << (char)h;
										if (found_passwords_count != num_of_passwords_to_find) s << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return found_passwords_count;
}

int main()
{
	// REMEMBER: These passwords are not complete yet, do not forget to add any character before the generated password
	// due to the fact that the crackme only checks the characters 2-9 and not 1-8


	ofstream file;
	file.open("passwords.txt", ios_base::app);

	// I want to find my own password so i type uxXx (remember, do not enter the first character)
	// as far as i see there are at least 102340 passwords with uxXx
	cout << "\nI found " << bruteForce(file, -1, "uxXx") << " passwords.\n";
	system("pause");
	file.close();

    return 0;
}


#include "stdafx.h"
#include <iostream>
#include <fstream>
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
int bruteForce(ostream& s, long num_of_passwords_to_find) {
	int found_passwords_count = 0;
	for (int a = FIRST_CHAR; a <= LAST_CHAR; a++)
	{
		// no continue check necessary because 866-7*126 is -16, a will always be greater than -16
		for (int b = FIRST_CHAR; b <= LAST_CHAR; b++)
		{
			if (a + b < PASSWORD_SUM - 6 * LAST_CHAR) continue;
			for (int c = FIRST_CHAR; c <= LAST_CHAR; c++)
			{
				if (a + b + c < PASSWORD_SUM - 5 * LAST_CHAR) continue;
				for (int d = FIRST_CHAR; d <= LAST_CHAR; d++)
				{
					if (a + b + c + d < PASSWORD_SUM - 4 * LAST_CHAR) continue;
					for (int e = FIRST_CHAR; e <= LAST_CHAR; e++)
					{
						if (a + b + c + d + e < PASSWORD_SUM - 3 * LAST_CHAR) continue;
						for (int f = FIRST_CHAR; f <= LAST_CHAR; f++)
						{
							if (a + b + c + d + e + f < PASSWORD_SUM - 2 * LAST_CHAR) continue;
							for (int g = FIRST_CHAR; g <= LAST_CHAR; g++)
							{
								if (a + b + c + d + e + f + g < PASSWORD_SUM - 1 * LAST_CHAR) continue;
								for (int h = FIRST_CHAR; h <= LAST_CHAR; h++)
								{
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
	cout << "\nI found " << bruteForce(file, 100) << " passwords.\n";
	system("pause");
	file.close();

    return 0;
}


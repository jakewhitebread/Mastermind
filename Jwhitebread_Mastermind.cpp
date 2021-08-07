// Jake Whitebread
//CST-210
//2/10/19
//Mastermind Game

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int j, ranColor, a;
	bool same = true, same1 = true, same2 = true, again = true;
	string colors[6] = { "r", "g", "o", "b", "y", "w" }; 
	string secretCode[4];
	string play;
	srand((unsigned)time(0));
	while (again == true)
	{

		a = rand() % 6;
		secretCode[0] = colors[a];

		while (same == true)
		{
			a = rand() % 6;
			secretCode[1] = colors[a];

			if (secretCode[1] != secretCode[0]) //compares generated color to previous one to make sure it's not duplicate
			{
				same = false;
			}
		}

		while (same1 == true)
		{
			a = rand() % 6;
			secretCode[2] = colors[a];

			if (secretCode[2] != secretCode[0] && secretCode[2] != secretCode[1]) //compares generated color to previous ones to make sure it's not a duplicate
			{
				same1 = false;
			}
		}

		while (same2 == true)
		{
			a = rand() % 6;
			secretCode[3] = colors[a];

			if (secretCode[3] != secretCode[0] && secretCode[3] != secretCode[1] && secretCode[3] != secretCode[2]) //compares generated color to previous ones to make sure it's not a duplicate
			{
				same2 = false;
			}
		}
		//used this method to generate secretCode, because duplicates caused glitches when giving color of pegs.
		cout << "Welcome to mastermind!" << "\n"; //The secret code is : " << secretCode[0] << secretCode[1] << secretCode[2] << secretCode[3] << "\n";

		cout << R"(Here are the rules: 
		1. The sequence can contain pegs of the following colors: r, g, o, b, y, w.
		2. There are no duplicates in the generated code.
		3. All four pegs of the secret sequence will contain a color - no blanks/empties are allowed.
		4. Each guess must consist of 4 peg colors - no blanks.
		5. You have 8 guesses to find the secret sequence.
		6. If you guess a color correctly, but it is not in the right spot the computer will give you a "W".
	    If you guess both the color and position of a dot correctly the computer will give you a "R".)";
		cout << "\n";

		int turnCounter = 0;
		string userPicks[4];

		do
		{
			turnCounter++;

			cout << "\nTry #: " << turnCounter << endl;

			for (int i = 0; i < 4; i++)
			{
				cout << "Pick a color " << i << " (r,g,b,w,y,o): ";
				cin >> userPicks[i];
			}
			cout << userPicks[0] << userPicks[1] << userPicks[2] << userPicks[3] << "\n";

			if (userPicks[0] == secretCode[0] &&
				userPicks[1] == secretCode[1] &&
				userPicks[2] == secretCode[2] &&
				userPicks[3] == secretCode[3])
			{
				cout << "\nYou cracked the code! It took " << turnCounter << " tries. ";
				cout << "\nThe code was: " << secretCode[0] << secretCode[1] << secretCode[2] << secretCode[3];
				return 0;
			}

			for (int b = 0; b < 4; b++)
			{
				if (secretCode[b] == userPicks[b])
				{
					userPicks[b] = "X";
					cout << "R" << " ";
				}
			}

			for (int b = 0; b < 4; b++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (secretCode[b] == userPicks[j])
					{
						userPicks[j] = "X";
						cout << "W" << " ";
					}
				}
			}

		} while (turnCounter != 8);
		cout << "\nYou failed to crack the code. ";
		cout << "\nThe code was: " << secretCode[0] << secretCode[1] << secretCode[2] << secretCode[3];
		cout << "\nDo you want to play again? Yes or No: ";
		cin >> play;
		if (play != "Yes")
		{
			again = false;
			cout << "\nThank you for playing!";
			return 0;
		}
	}
}


/*for (j = 0; j < 4; j++)
{
	ranColor = rand() % 6 + 1;
	switch (ranColor)
	{
	case 1:
		secretCode[j] = 'r';
		break;
	case 2:
		secretCode[j] = 'g';
		break;
	case 3:
		secretCode[j] = 'o';
		break;
	case 4:
		secretCode[j] = 'b';
		break;
	case 5:
		secretCode[j] = 'y';
		break;
	case 6:
		secretCode[j] = 'w';
		break;

	}
}*/
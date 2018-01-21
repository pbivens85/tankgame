#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

char board[9][9] = { NULL };

int american_tank_att = 5;
int russian_tank_att = 4;

int american_tank_def = 3;
int russian_tank_def = 5;

int american_tank_hp = 5;
int russian_tank_hp = 5;

char dir = NULL;
int num = 0;

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = '.';
		}
	}

	board[4][4] = 'A';
	board[2][6] = 'R';

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	int i = 4;
	int j = 4;
	int m = 2;
	int n = 6;
	
	while (dir != 'q')
	{
		cout << endl;
		cout << "***American***" << endl;
		cout << "American Tank" << endl;
		cout << "Move Forward (w): " << endl;
		cout << "Move Left (a): " << endl;
		cout << "Move Right (d): " << endl;
		cout << "Move Back (x): " << endl;
		cout << "Quit (q): " << endl;
		cout << endl;

		cout << "Enter American Tank Command (w,a,d,x,q): ";
		cin >> dir;
		cout << endl;

		switch (dir)
		{
		case 'w':
			board[i][j] = '.';
			i--;
			if (i <= 0)
			{
				i = 0;
			}
			break;
		case 'x':
			board[i][j] = '.';
			i++;
			if (i >= 8)
			{
				i = 8;
			}
			break;
		case 'a':
			board[i][j] = '.';
			j--;
			if (j <= 0)
			{
				j = 0;
			}
			break;
		case 'd':
			board[i][j] = '.';
			j++;
			if (j >= 8)
			{
				j = 8;
			}
			break;
		case 'q':
			cout << "Exiting " << endl;
			cout << endl;
			system("pause");
			return 0;
			break;
		}
		
			board[i][j] = 'A';

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << board[i][j];
				}
				cout << endl;
			}
			
			num = rand() % 4 + 1;

			cout << endl;
			cout << "***Russian***" << endl;
			cout << "Russian Tank";
			cout << endl;

			switch (num)
			{
			case 1:
				board[m][n] = '.';
				m--;
				if (m <= 0)
				{
					m = 0;
				}
				break;
			case 2:
				board[m][n] = '.';
				m++;
				if (m >= 8)
				{
					m = 8;
				}
				break;
			case 3:
				board[m][n] = '.';
				n--;
				if (n <= 0)
				{
					n = 0;
				}
				break;
			case 4:
				board[m][n] = '.';
				n++;
				if (n >= 8)
				{
					n = 8;
				}
				break;
			}
				board[m][n] = 'R';
				
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						cout << board[i][j];
					}
					cout << endl;
				}
				
				if (board[m][n] == board[i][j])
				{
					board[i][j] = 'A';
					
					int att_american = rand() % 6 + 1;
					int att_russian = rand() % 6 + 1;

					if (att_american >= 1 && att_american <= 3)
					{
						cout << "Russian Tank Missed" << endl;
					}

					if (att_american == 4)
					{
						russian_tank_hp -= 1;
						cout << "Russian Tank Hit for One Point" << endl;
					}
					if (att_american == 5)
					{
						russian_tank_hp -= 2;
						cout << "Russian Tank Hit for Two Points" << endl;
					}
					if (att_american == 6)
					{
						russian_tank_hp -= 3;
						cout << "Russian Tank Hit for Three Points" << endl;
					}

					if (att_russian >= 1 && att_russian <= 2)
					{
						cout << "American Tank Missed" << endl;
					}
					if (att_russian == 3)
					{
						american_tank_hp -= 1;
						cout << "American Tank Hit for One Point" << endl;
					}
					if (att_russian == 4)
					{
						american_tank_hp -= 2;
						cout << "American Tank Hit for Two Points" << endl;
					}
					if (att_russian == 5)
					{
						american_tank_hp -= 3;
						cout << "American Tank Hit for Three Points" << endl;
					}
					if (att_russian == 6)
					{
						american_tank_hp -= 4;
						cout << "American Tank Hit for Four Points" << endl;
					}

					if (russian_tank_hp <= 0)
					{
						cout << "American Tank Wins" << endl;
					}
					if (american_tank_hp <= 0)
					{
						cout << "Russian Tank Wins" << endl;
					}
				}

		}
	
	system("pause");
	return 0;
}
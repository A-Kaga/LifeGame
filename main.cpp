#include<iostream>

const int MAXROW = 50;
const int MAXCOL = 50;

using namespace std;

class Life
{
public:
	Life();
	~Life();

	int marix[MAXROW + 2][MAXCOL + 2];

	void inti()
	{
		for (int i = 0; i <= MAXROW + 1; i++)
			for (int j = 0; j <= MAXCOL + 1; j++)
				marix[i][j] = 0;

		int row = 0;
		int col = 0;
		cout << "Input intger pairs, input 1 to end" << endl;
		cin >> row >> col;
		while (row != -1 || col != -1)
		{
			if (col > 0 && col < MAXCOL + 1)
				if (row > 0 && col < MAXROW + 1)
					marix[row][col] = 1;
				else
					cout << "Row value is out of range" << endl;
			else
				cout << "Col value is out of range" << endl;
			cin >> row >> col;
		}
	}

	void update()
	{
		int new_marix[MAXROW + 2][MAXCOL + 2] = { 0 };
		for (int i = 1; i < MAXROW + 1; i++)
			for (int j = 1; j < MAXCOL + 1; j++)
				switch (count(i, j))
				{
					case 2:
						new_marix[i][j] = marix[i][j];
						break;
					case 3:
						new_marix[i][j] = 1;
						break;
					default:
						new_marix[i][j] = 0;
						break;
				}

		for (int i = 1; i < MAXROW + 1; i++)
			for (int j = 1; j < MAXCOL + 1; j++)
				marix[i][j] = new_marix[i][j];
	}

	void display()
	{
		cout << "Current life" << endl;
		for (int i = 1; i < MAXROW + 1; i++)
		{
			for (int j = 1; j < MAXCOL + 1; j++)
			{
				if (marix[i][j] == 1)
					cout << '*';
				else
					cout << '_';
			}
			cout << endl;
		}	
	}

	int count(int row, int col)
	{
		int count = 0;
		for (int i = row - 1; i <= row + 1; i++)
			for (int j = col - 1; j <= col + 1; j++)
				if (marix[i][j] == 1)
					count++;
		return count - marix[row][col];
	}
};


bool yes_no()
{
	char choice;
	cout << "Continue? (y/n)" << endl;
	cin >> choice;
	if (choice == 'y')
		return true;
	else
		return false;
//行，我知道这里很烂
}


void main()
{
	Life me;
	me.inti();
	do
	{
		me.display();
		me.update();
	} while (yes_no());
	getchar();
	getchar();
}
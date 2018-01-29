/*
Project: Tic-Tac-Toe
File: main.cpp
Author: Muzaffar Auhammud
License: MIT License
*/

#include <iostream>

using namespace std;

char grid[3][3];
char player;

bool RowFull(int row)
{
    return (grid[row][0] != '-' && grid[row][1] != '-' && grid[row][2] != '-');
}

bool RowAlign(int row)
{
    return (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]);
}

bool ColumnFull(int column)
{
    return (grid[0][column] != '-' && grid[1][column] != '-' && grid[2][column] != '-');
}

bool ColumnAlign(int column)
{
    return (grid[0][column] == grid[1][column] && grid[1][column] == grid[2][column]);
}

bool Diagonal1Full()
{
    return (grid[0][0] != '-' && grid[1][1] != '-' && grid[2][2] != '-');
}

bool Diagonal1Align()
{
    return (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]);
}

bool Diagonal2Full()
{
    return (grid[2][0] != '-' && grid[1][1] != '-' && grid[0][2] != '-');
}

bool Diagonal2Align()
{
    return (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]);
}

bool HasWinner()
{
    bool winner = false;

    for (int i = 0; i < 3; i++)
    {
        if((RowFull(i) && RowAlign(i)) || (ColumnFull(i) && ColumnAlign(i)))
        {
            winner = true;
            break;
        }
    }

    if((Diagonal1Full() && Diagonal1Align()) || (Diagonal2Full() && Diagonal2Align()))
    {
         winner = true;
    }

    return winner;
}

void PrintGrid()
{
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << '\t';
        }

        cout << endl;
    }

    cout << endl;
}

void Convert1Dto2D (int pos, int &row, int &column)
{
    row = pos / 3;
    column = pos % 3;
}

bool GridFull()
{
    bool IsFull = true;

    for(int i = 0; i < 3; i++)
    {
        if(!IsFull)
        {
            break;
        }

        for(int j = 0; j < 3; j++)
        {
            if(grid[i][j] == '-')
            {
                IsFull = false;
                break;
            }
        }
    }

    return IsFull;
}

void PromptPlayer(char token)
{
    int pos;
    int row;
    int column;

    cout << "Player (" << token << ") - Enter a cell position (1 - 9) to mark your move: ";
    cin >> pos;
    Convert1Dto2D(pos - 1, row, column);

    while (pos < 1 || pos > 9 || grid[row][column] != '-')
    {
        cout << "Error: Cell " << pos << " does not exist or is already full!" << endl << endl;;
        cout << "Player (" << token << ") - Enter a cell position (1 - 9) to mark your move: ";
        cin >> pos;
        Convert1Dto2D(pos - 1, row, column);
    }

    grid[row][column] = token;
    player = token;
    PrintGrid();
}

bool GameOver()
{
	if(HasWinner())
    {
        cout << "Congratulations Player (" << player << ") !!!";
        return true;
    }
    else if(GridFull())
    {
        cout << "Grid is full! It's a draw!";
        return true;
    }
	else
	{
		return false;
	}
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = '-';
        }
    }

    PrintGrid();

    while(true)
    {
        PromptPlayer('O');

        if(GameOver())
		{
			break;
		}

        PromptPlayer('X');

        if(GameOver())
		{
			break;
		}
    }

	return 0;
}
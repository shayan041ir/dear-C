#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> directions = {"left", "right", "up", "down"};

void printMaze(vector<vector<char>> &maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> maze = {
        {'S', '.', '#', '#', '#'},
        {'.', '.', '.', '.', '#'},
        {'#', '#', '.', '#', '#'},
        {'.', '.', '.', '.', 'E'}};

    int satr = 0;
    int sutun = 0;
    char move;

    printMaze(maze);

    bool efa = false;

    while (!efa)
    {
        cout << "Enter your move (l-left, r-right, u-up, d-down): ";
        cin >> move;

        if (move == 'l' && sutun > 0)
        {
            sutun--;
            system("cls");
        }
        else if (move == 'r' && sutun < maze[0].size() - 1)
        {
            sutun++;
            system("cls");
        }
        else if (move == 'u' && satr > 0)
        {
            satr--;
            system("cls");
        }
        else if (move == 'd' && satr < maze.size() - 1)
        {
            satr++;
            system("cls");
        }
        else
        {
            cout << "try again!" << endl;
            continue;
        }

        if (maze[satr][sutun] == 'E')
        {
            efa = true;
        }
        if (maze[satr][sutun] != '#')
        {
            maze[satr][sutun] = 'P';
        }
        else
        {
            if (move == 'l')
            {
                sutun++;
            }
            else if (move == 'r' )
            {
                sutun--;
            }
            else if (move == 'u')
            {
                satr++;
            }
            else if (move == 'd')
            {
                satr--;
            }
            printMaze(maze);
            cout << "try again!\n";
            continue;
        }

        printMaze(maze);
    }

    cout << "Congratulations, you have found the way." << endl;

    return 0;
}
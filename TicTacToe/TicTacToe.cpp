#include <iostream>

bool CheckWin(char grid[3][3]);

int main()
{
    /*
        Construct a 3x3 grid, with all values initially 0 (a 2D array)
        Get row and column from player to input O/X
        Start checking for winner starting from 5th turn

        Check by if-else whether column, row, or 2 diagonals are equal

        char 0 = int 48
        char 1 = int 49
        char 2 = int 50
    */

    std::cout << "Welcome to Tic Tac Toe\n";

    char grid[3][3]{ ' ', ' ', ' ',
                     ' ', ' ', ' ',
                     ' ', ' ', ' ', };

    int turn = 1;
    char row, col;
    bool bvalid = false;

    std::cout << "We'll start with O, then X.\nPlease enter a row followed by a column.\n";

    std::cout << "-------------" << std::endl;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            std::cout << "| " << grid[r][c] << " ";
        }
        std::cout << "|" << std::endl << "-------------" << std::endl;
    }

    while (turn < 10)
    {
        char move = (turn % 2 != 0) ? 'O' : 'X';

        bvalid = false;
        do
        {
            std::cout << "\nTurn #" << turn << std::endl;
            std::cout << ">> ";
            std::cin >> row >> col;

            if (grid[int(row) - 48][int(col) - 48] == ' ')
            {
                grid[int(row) - 48][int(col) - 48] = move;
                bvalid = true;
            }
            else
                std::cout << "Already played. Try again.\n";

        } while (bvalid == false);

        turn++;

        //grid[int(row) - 48][int(col) - 48] = 'O';
        //std::cout << grid[int(row) - 48][int(col) - 48] << std::endl;

        std::cout << "-------------" << std::endl;

        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                std::cout << "| " << grid[r][c] << " ";
            }
            std::cout << "|" << std::endl << "-------------" << std::endl;
        }

        if (turn > 4)
        {
            if (CheckWin(grid) == true)
            {
                std::cout << "\n\n" << move << " wins!\n\n";
                return 0;
            }
        }

    }

    std::cout << "\nTIE.\n";

    return 0;
}

bool CheckWin(char grid[3][3])
{
    /*
        Same row, check all 3 cols
            Move to next row, repeat

        Same col, check all 3 rows
            Move to next col, repeat

        Check both diagonals
    */

    for (int r = 0; r < 3; r++)
    {
        if (grid[r][0] == ' ' || grid[r][1] == ' ' || grid[r][2] == ' ')
            break;
        if (grid[r][0] == grid[r][1] && grid[r][1] == grid[r][2])
            return true;
    }

    for (int c = 0; c < 3; c++)
    {
        if (grid[0][c] == ' ' || grid[1][c] == ' ' || grid[2][c] == ' ')
            break;
        if (grid[0][c] == grid[1][c] && grid[1][c] == grid[2][c])
            return true;
    }

    // 0,0
    // 1,1
    // 2,2

    for (int r = 0; r < 3; r++)
    {
        if (grid[r][r] == ' ' || grid[r + 1][r + 1] == ' ' || grid[r + 2][r + 2] == ' ')
            break;
        if (grid[r][r] == grid[r + 1][r + 1] && grid[r + 1][r + 1] == grid[r + 2][r + 2])
            return true;
        else
            break;
    }

    for (int r = 2; r >= 0; r--)
    {
        if (grid[r][r - 2] == ' ' || grid[r - 1][r - 1] == ' ' || grid[r - 2][r] == ' ')
            break;
        if (grid[r][r - 2] == grid[r - 1][r - 1] && grid[r - 1][r - 1] == grid[r - 2][r])
            return true;
        else
            break;
    }

    return false;
}


#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

void print_board(char* board)
{
    int width = 5;
    std::cout << std::setw(width) << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << std::setw(width) << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << std::endl;
    std::cout << std::setw(width) << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << std::setw(width) << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << std::endl;
    std::cout << std::setw(width) << board[6] << " | " << board[7] << " | " << board[8] << std::endl;

}


char check_win(char* board)
{
    bool tie = true;

    // checks for all possible win combinations
    if (board[0] == board[1] && board[1] == board[2])
        return board[0];
    else if (board[3] == board[4] && board[4] == board[5])
        return board[3];
    else if (board[6] == board[7] && board[7] == board[8])
        return board[6];
    else if (board[0] == board[3] && board[3] == board[6])
        return board[0];
    else if (board[1] == board[4] && board[4] == board[7])
        return board[1];
    else if (board[2] == board[5] && board[5] == board[8])
        return board[2];
    else if (board[0] == board[4] && board[4] == board[8])
        return board[0];
    else if (board[2] == board[4] && board[4] == board[6])
        return board[2];
    
    // Checks if the board is still default
    // if the board has any default chars then it sets tie to false
    char defaultboard[9] = { '1','2','3','4','5','6','7','8','9' };
    for (size_t i = 0; i < 9; i++)
    {
        
        if (board[i] == defaultboard[i])
            tie = false;
    }

    if (tie)
        return 'T';
    else
        return '0';
}


int main()
{
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    bool playing = 0;
    bool turn = 0;
    char answer;

    std::cout << "Would you like to play a game of Tic-Tac-Toe?\n";
    std::cout << "[1] Yes [2] No\n:";
    std::cin >> answer;

    if (answer == '1')
        playing = true;

    while (playing) {

        system("CLS");
        std::cout << "Let the Game Begin!\n\n";
        print_board(board);

        if (!turn)
            std::cout << "\nPlayer 1 pick a number: ";
        else
            std::cout << "\nPlayer 2 pick a number: ";

        std::cin >> answer;

        // subtract 48 to convert from ascii to int then subtract 1 for index of array
        if (board[answer - 48 - 1] != 'X' && board[answer - 48 - 1] != 'O')
        {
            if (!turn)
                board[answer - 48 - 1] = 'X';
            else
                board[answer - 48 - 1] = 'O';
        }
        else
        {
            if (!turn)
                turn = true;
            else
                turn = false;
        }

        // change between playrs
        if (!turn)
            turn = true;
        else
            turn = false;

        //check if someone won
        char win = check_win(board);
        if (win == 'X')
        {
            system("CLS");
            std::cout << "Player 1 Wins!!!\n";
            playing = false;
        }
        else if (win == 'O')
        {
            system("CLS");
            std::cout << "Player 2 Wins!!!\n";
            playing = false;
        }
        else if (win == 'T')
        {
            system("CLS");
            std::cout << "Tie\n";
            playing = false;
        }
    }
    std::cout << "Thanks for playing :)\n";
    return 0;
}


#include <iostream>
#include <windows.h>
#define getch() _getch()
int GameBoardMatrix[4][4];

void printBoardMatrix() // Print Board - c  Column, l Line
{
    for (int c = 0; c < 4; ++c)
    {
        for (int l = 0; l < 4; ++l)
            if (GameBoardMatrix[c][l] == 0) // if 0 print dot 
            {
                printf(" . ");
            }
            else
            {
                printf(" %d ", GameBoardMatrix[c][l]); // Print numbers in matrix 
            }
        printf("\n"); // New line if line in matrix has numbers or dots
    }
}

int mainmenu() // Main menu
{
    printf("2048\nNew game: n\nContinue game: c\nLeaderboard: l\nQuit : q\n");

    char input; // User Input in Main Menu 
    scanf_s(" %c", &input, 1);
    bool inprogress;
    if (input == 'n') // Play new Game
    {
        inprogress = true;
        printBoardMatrix();
        while (inprogress == true)
        {
            // Game();
            Sleep(5000);
            inprogress = false;
        }
        mainmenu();
    }
    else if (input == 'c') // Continue Game
    {
        inprogress = true;
        printBoardMatrix();
        while (true)
        {
            // ContinueGame();
            Sleep(5000);
            inprogress = false;
        }
        mainmenu();
    }
    else if (input == 'q') // Quit game
    {
        return 0;
    }
}

void game() // Main Game Script - put all things in here, Do not bloat code with copying this to ContinueGame, load state and call game
{

}
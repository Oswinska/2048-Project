#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include "Header.h"
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

int random2() // Randomly generate num 2 on an empty space 
{
   srand(time(NULL));
   Sleep(1);
    int c = rand() % 4;
    int l = rand() % 4;
    bool nezapsan = true;
    while (nezapsan == true)
    {
        if (GameBoardMatrix[c][l] == 0)
        {
            GameBoardMatrix[c][l] = 2;

            system("cls");
            printBoardMatrix();
            nezapsan = false;

        }
        else
        {
            random2();
            nezapsan = false;
        }
    }
    return 0;
}

int mainmenu() // Main menu
{
    system("cls");
    printf("2048\nNew game: n\nContinue game: c\nLeaderboard: l\nQuit : q\n");

    //char input; // User Input in Main Menu - Old Code
    int input; 
    //scanf_s(" %c", &input, 1); - Old Code
    input = controls();
    bool inprogress;
    if (input == 110) // Play new Game
    {
        inprogress = true;
       // printBoardMatrix();
        while (inprogress == true)
        {
           
            game();
            inprogress = false;
        }
        mainmenu();
    }
    else if (input == 99 ) // Continue Game
    {
        inprogress = true;
        printBoardMatrix();
        while (inprogress == true)
        {
            //ContinueGame;
            controls();
            Sleep(5000);
            inprogress = false;
        }
        mainmenu();
    }
    else if (input == 108) // Leaderboard 
    {
        system("cls");
        printf("Lmao leaderboarda here");
        Sleep(5000);
        mainmenu();
    }
    else if (input == 27) // Quit game
    {
        return 0;
    }
   
}

void game() // Main Game Script - put all things in here, Do not bloat code with copying this to ContinueGame, load state and call game
{
    random2();
    while (1)
    {
    gamecontrols();
    
    }
}

void left() // Move numbers in Array to the left - Ignore Merging
{
    for (int c = 0; c < 4; c++)       // Scan Matrix  c - column l - line
        for (int l = 0; l < 4; l++)
        {
            if (!GameBoardMatrix[c][l])    // If tile is empty
            {
                for (int k = l + 1; k < 4; k++)  // 
                    if (GameBoardMatrix[c][k])
                    {
                        GameBoardMatrix[c][l] = GameBoardMatrix[c][k]; // Move the non-zero element to the empty tile
                        GameBoardMatrix[c][k] = 0;          // Assign the non-zero element with zero

                    }
            }
        }
}

/*void right()

void up()

void down()
*/
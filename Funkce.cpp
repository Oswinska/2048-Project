#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include "Header.h"
int GameBoardMatrix[4][4];

void clearmatrix()
{
   for (int y = 0; y < 4; ++y)
    {
       for (int x = 0; x < 4; ++x)
       {
           GameBoardMatrix[x][y] = 0;
       }
    }
}

void printBoardMatrix() // Print Board - y Up, Down,  x - Left, Right
{
    system("cls");
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 4; ++x)
            if (GameBoardMatrix[x][y] == 0) // if 0 print dot 
            {
                printf(" . ");
            }
            else
            {
                printf(" %d ", GameBoardMatrix[x][y]); // Print numbers in matrix 
            }
        printf("\n"); // New line if line in matrix has numbers or dots
    }
}

void random2()
{
    srand(time(NULL));
    Sleep(1);
    int x = rand() % 4;
    int y = rand() % 4;

    if (GameBoardMatrix[x][y] == 0)
    {
        GameBoardMatrix[x][y] = 2;
        printBoardMatrix();
    }
    else
        random2();
}

int mainmenu() // Main menu
{
    system("cls");
    printf("2048\nNew game: n\nContinue game: c\nLeaderboard: l\nQuit : q\n");

    int input;
    input = controls();
    bool inprogress;

    switch (input)
    {
    case 110: //New Game
        inprogress = true;
        while (inprogress == true)
        {
            clearmatrix();
            game();
            inprogress = false;
        }
        mainmenu();
        break;
    case 99:  //Continue game
        inprogress = true;
        while (inprogress == true)
        {
            controls();
            //loadstate();
            //game()
            Sleep(5000);
            inprogress = false;
        }
        mainmenu();
        break;
    case 108: //Leaderboard
        system("cls");
        printf("Lmao leaderboarda here");
        Sleep(5000);
        mainmenu();
        break;
    case 27: //ESC
        return 0;
        break;
    }
}

int score() // Is highscore the highest achieved number or sum of all numbers in the matrix ?
{
    int max = GameBoardMatrix[0][0];
    int static sum = 0;
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (GameBoardMatrix[x][y] > max)
                max = GameBoardMatrix[x][y];
    sum += max;
    return sum;
}

void loadstate()
{

}

void game() // Main Game Script - put all things in here, Do not bloat code with copying this to ContinueGame, load state and call game
{
    random2();
    bool inprogress = true;
    while (inprogress == true)
    {
        int input = gamecontrols();
        printf("score: %d", score());
        if (input == 0)
        inprogress = false;
        if (WinCon() == 1)
            inprogress = false;
    }
}

void save()
{
    FILE* end;
    errno_t errorCode1 = fopen_s(&end, "save_1.dat", "w");
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            fprintf(end, "%d", GameBoardMatrix[x][y]);
        }
        fprintf(end, "\n");
    }
    fprintf(end, "\nScore:%d", score());
    fclose(end);
    mainmenu();
}

int WinCon() // Check for 2048, if its present, end the game.
{
    int max = GameBoardMatrix[0][0];
    int static sum = 0;
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (GameBoardMatrix[x][y] > max)
                max = GameBoardMatrix[x][y];
    sum += max;
    if (max == 2048) // change to 16 for testing
    {
        Endgame();
        return 1;
    }
    return 0;
}

void Endgame()
{
    system("cls");
    printf("Nice");
    Sleep(5000);
}

void up() // Move numbers in Array up - ignore merging
{
    for (int x = 0; x < 4; x++)       // Traverse from Top to bottom of a column
        for (int y = 0; y < 4; y++)
        {
            if (!GameBoardMatrix[x][y])    // If tile is empty
            {
                for (int k = y + 1; k < 4; k++)  // Traverse below to find a non-zero element
                    if (GameBoardMatrix[x][k])
                    {
                        GameBoardMatrix[x][y] = GameBoardMatrix[x][k]; // Move the non-zero element to the empty tile
                        GameBoardMatrix[x][k] = 0;          // Assign the non-zero element with zero
                        y++; // Move "zero scanner" to not write other numbers to this
                    }
            }
        }
    for (int x = 0; x < 4; x++)       // Traverse from Top to bottom of a column
        for (int y = 0; y < 4; y++)
        {
            if (GameBoardMatrix[x][y] && GameBoardMatrix[x][y] == GameBoardMatrix[x][y + 1]) // Check Tile is non zero and
            {                                        // adjacent tile is equal
                GameBoardMatrix[x][y] += GameBoardMatrix[x][y + 1];             // add to first element or double
                GameBoardMatrix[x][y + 1] = 0;                       // assign second element with zero
            }
        }
}

void down() //Move Numbers in Array down - Ignore Merging
{

    for (int x = 3; x >= 0; x--)       // Traverse from bottom to top of a column
        for (int y = 3; y >= 0; y--)
        {
            if (!GameBoardMatrix[x][y])    // If tile is empty
            {
                for (int k = y - 1; k >= 0; k--)  // Traverse below to find a non-zero element
                    if (GameBoardMatrix[x][k])
                    {
                        GameBoardMatrix[x][y] = GameBoardMatrix[x][k]; // Move the non-zero element to the empty tile
                        GameBoardMatrix[x][k] = 0;  // Assign the non-zero element with zero
                        y--; // Move "zero scanner" to not write other numbers to this
                    }
            }
        }
    for (int x = 3; x >= 0; x--)       // Traverse from bottom to top of a column
        for (int y = 3; y >= 0; y--)
        {
            if (GameBoardMatrix[x][y] && GameBoardMatrix[x][y] == GameBoardMatrix[x][y - 1]) // Check Tile is non zero and adjacent tile is equal
            {
                GameBoardMatrix[x][y] += GameBoardMatrix[x][y - 1];             // add to first element or double
                GameBoardMatrix[x][y - 1] = 0;                       // assign second element with zero
            }
        }
}

void left() // Move numbers in Array to the left - Ignore Merging
{
    for (int y = 0; y < 4; y++)       // Scan Matrix  c - column l - line, scan from left to right
        for (int x = 0; x < 4; x++)
        {
            if (!GameBoardMatrix[x][y])    // If tile is empty
            {
                for (int k = x + 1; k < 4; k++)  // 
                    if (GameBoardMatrix[k][y])
                    {
                        GameBoardMatrix[x][y] = GameBoardMatrix[k][y]; // Move the non-zero element to the empty tile
                        GameBoardMatrix[k][y] = 0;          // Assign the non-zero element with zero
                        x++; // Move "zero scanner" to not write other numbers to this
                    }
            }
        }
    for (int y = 0; y < 4; y++)       // Scan Matrix  c - column l - line, scan from left to right
        for (int x = 0; x < 4; x++)
        {
            if (GameBoardMatrix[x][y] && GameBoardMatrix[x][y] == GameBoardMatrix[x + 1][y])//Check if adjecent tiles are equaland non zero
            {
                GameBoardMatrix[x][y] += GameBoardMatrix[x + 1][y];
                GameBoardMatrix[x + 1][y] = 0;
            }
        }
}

void right() // Move numbers in Array to the right - Ignore Merging
{
    for (int y = 3; y >= 0; y--)       // Scan Matrix  c - column l - line, scan from right to left
        for (int x = 3; x >= 0; x--)
        {
            if (!GameBoardMatrix[x][y])    // If tile is empty
            {
                for (int k = x - 1; k >= 0; k--)  // Look for Empty tile
                    if (GameBoardMatrix[k][y])
                    {
                        GameBoardMatrix[x][y] = GameBoardMatrix[k][y]; // Move the non-zero element to the empty tile
                        GameBoardMatrix[k][y] = 0;          // Assign the non-zero element with zero
                        x--; // Move "zero scanner" to not write other numbers to this
                    }
            }

        }
    for (int y = 0; y < 4; y++)       // Scan Matrix  c - column l - line, scan from left to right
        for (int x = 0; x < 4; x++)
        {
            if (GameBoardMatrix[x][y] && GameBoardMatrix[x][y] == GameBoardMatrix[x - 1][y]) // Check if adjecent tiles are equal and non zero
            {
                GameBoardMatrix[x][y] += GameBoardMatrix[x - 1][y]; // add
                GameBoardMatrix[x - 1][y] = 0;// Assign 0 to second element
            }
        }
}
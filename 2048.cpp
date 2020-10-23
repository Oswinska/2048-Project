
#include <iostream>

int GameBoardMatrix[4][4]; // Matice Herního Pole
int X[] = {-1,1,0,0 } ;  // Levo, Pravo, Nahoru, Dolu
int Y[] = {0,0,1,-1}; // -..-

void NewGame () // Funkce Nové hry - Nuluje Herní Pole
{
    for (int s = 0 ; s < 4; ++s)  //  s = Sloupec - Nulování Sloupců  
    for (int r = 0; r < 4; ++r) // r = Řádek - Nulování řádků
        GameBoardMatrix [s][r] = 0 ; // Nulování
}

void printBoardMatrix () // Tisk herního pole

#include <iostream>
#include <ctime>
#include <cstdlib> // Pomoc při generování random pozice pro spawn dvojek
using namespace std; // Nechápu co to je, ale potřebuju to na funkci pair
int GameBoardMatrix[4][4]; // Matice Herního Pole
int X[] = { -1,1,0,0 };  // Levo, Pravo, Nahoru, Dolu
int Y[] = { 0,0,1,-1 }; // -..-

pair <int, int> Espace() { //Dvojička pro hledání volného místa v arrayi, Espace = EmptySpace  Fspace = FullSpace
    int Fspace = 1, line, column;
    while (Fspace)
    {
        line = rand() % 4;
        column = rand() % 4;
        if (GameBoardMatrix[line][column] == 0)
            Fspace = 0;

    }
    return make_pair(line, column);
}


void NewGame() // Funkce Nové hry - Nuluje Herní Pole
{
    for (int s = 0; s < 4; ++s)  //  s = Sloupec - Nulování Sloupců  
        for (int r = 0; r < 4; ++r) // r = Řádek - Nulování řádků
            GameBoardMatrix[s][r] = 0; // Nulování
    pair<int, int> pos = Espace();
    GameBoardMatrix[pos.first][pos.second] = 2; // Zapsání 2 do random pozice 
}

void printBoardMatrix() // Tisk herního pole
{
    for (int s = 0; s < 4; ++s) {
        for (int r = 0; r < 4; ++r)
            if (GameBoardMatrix[s][r] == 0)
            {
                printf(".");
            }
            else
            {
                printf(" %d ", GameBoardMatrix[s][r]);
            }
        printf("\n");
    }
    printf("New Game: n ;Quit Game: q; Controls: I J K L\nInput: "); // Print Ovládání - jasné, možná implementovat print pouze jednou / při startu nové hry
}
bool KonecMatice(int line, int column, int Cstep, int Lstep)
{
    if (Lstep < 0 || Cstep < 0 || Cstep >= 4 || Lstep >= 4 || GameBoardMatrix[line][column] != GameBoardMatrix[Lstep][Cstep] && GameBoardMatrix[Lstep][Cstep] != 0)
        return false;
    return true;
}

void pohyb(int smer) // Pohnutí pole ve směru x
{
    int Line = 0, Column = 0, Lstep = 1, Cstep = 1;
    if (smer == 0)
    {
        Column = 3;
        Cstep = -1;
    }
    if (smer == 1)
    {
        Column = 0;
        Cstep = 1;
    }
    if (smer == 2)
    {
        Line = 3;
        Lstep = 1;
    }
    if (smer == 4)
    {
        Line = 0;
        Lstep = -1;
    }
    for (int i = Line ; i >=0 && i <4; i += Lstep)
        for (int j = Column; j >= 0 && j < 4; j += Cstep)
        {
            int nexti = i + X[smer], nextj = j + Y[smer];
            if (KonecMatice(i, j, nexti, nextj))
            {
                GameBoardMatrix[nexti][nextj] += GameBoardMatrix[i][j];
                GameBoardMatrix[i][j] = 0;
            }

        }

}

int main()
{
    char chpozice[128]; // Teoreticky je to mapování kláves pro změnu pozice, 128 protože ASCII pro Abecedu končí 127. Možná změnit mapování na přímé hodnoty I J K L
    chpozice['j'] = 0;
    chpozice['l'] = 1;
    chpozice['i'] = 2;
    chpozice['k'] = 3;
    srand(time(0)); // generátor čísel 
    while (true)
    {
        printBoardMatrix(); // Tiskni Hrací Pole
        char input;  // Vstup 
        scanf_s(" %c", &input,1); // Uživatelský vstup
        if (input == 'n')  // Pokud je vstup n začni novou hru
        {
            NewGame();
        }
        else if (input == 'q') // Pokud je vstup q vypni hru
        {
            break;
        }
        else
        {
            int pozice = chpozice[input]; 
            pohyb(pozice); // Funkce pro pohyb pole, should work 
        

        }
    }
}

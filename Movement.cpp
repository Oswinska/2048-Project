#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include <conio.h>
#include "Header.h"
#define getch() _getch()

int controls() // Keyboard controls - for MainMenu
{
	unsigned int key;
		key = getch();
        if (key == 0 || key == 0xE0) {
            key = getch();
        }
		return key;
}

int gamecontrols()
{
    
    int input = controls();

    if (input == 27) // ESC
    {
        return 0;
    }
    else if (input == 72) {

       up();
       random2();
    }
    else if (input == 80)
    {
        down();
        random2();
    }
    else if (input == 75)
    {
        left();
        random2();
    }
    else if (input == 77)
    {
        right();
        random2();
    }
    else
    {
        gamecontrols();
        // Dont quit on me 
    }
 

}
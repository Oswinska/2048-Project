#pragma once
// Game functions
int mainmenu();
void game();
void clearmatrix();
void printBoardMatrix();
void random2();
int gamecontrols();
//Controls
int controls();
void up();
void down();
void left();
void right();
//Save Load
int save();
int loadstate();
//GameState
int WinCon();
void endgame();
int adj();
//Leaderboard Struct
struct LeaderBoard
{
	char Username[256];
	int Score;
	struct Leaderboard* next;
};
void saveLead(char* Username, int* Score,struct Leaderboard** sh_first);
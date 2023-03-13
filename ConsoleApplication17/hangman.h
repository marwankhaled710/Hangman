#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<time.h>
using namespace std;
class word
{
public:
	string words;
	string category;
	word();
};
class hangman
{
//	vector<word>easy;
//	vector<word>medium;
//	vector<word>hard;
	vector<string> categories;

string getRandomCategory();
string randomword(string category, int lo, int hi);
void massege(string, bool, bool);
void drawhangman(int& wronggusses);
void letter(string, char, char);
void avilableletters(string);
bool printword(string, string);
int trails(string word, string gussed);
void play(string word, string category);
public:
	hangman();
	void startGame();
};
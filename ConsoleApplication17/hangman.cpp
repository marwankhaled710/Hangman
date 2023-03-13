#include "hangman.h"
using namespace std;



hangman::hangman()
{
	srand(time(NULL));
	categories = vector<string>{"animals", "movies", "fruit", "countries", "jobs"};
}

string hangman::getRandomCategory() {
	int index = rand() % categories.size();
	return categories[index];
}

void hangman:: massege(string m,bool upshape=true ,bool lowshape=true)
{
	if (upshape == true)
	{
		cout << "*-------------------------*" << endl;
		//cout << "|";

	}
	//else
	//{
		//cout << "|";
	//}


	cout << m;

	if (lowshape == true)
	{
		cout <<  endl;
		cout << "*-------------------------*" << endl;

	}
	cout << endl;

}
void hangman:: drawhangman(int& wronggusses )
{

	if (wronggusses == 8)
	{

		std::cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |   /|\\   " << endl
			<< "   |   / \\   " << endl
			<< "   |          " << endl
			<< "  ============" << endl << endl;
	}
	else if (wronggusses == 7)
	{
		std::cout << std::endl << std::endl
			<< "   +----+  " <<endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|\\ " << endl
			<< "   |     \\ " << endl
			<< "   |       " <<endl
			<< "  ============" << endl << endl;
	}
	else if (wronggusses == 6)
	{
		std::cout << endl << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|\\ " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else if (wronggusses == 5)
	{
		std::cout <<endl<< endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |   /|  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else if (wronggusses == 4)
	{
		cout << std::endl << endl
			<< "   +----+  " <<endl
			<< "   |    |  " << endl
			<< "   |    O  " << endl
			<< "   |    |  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else if (wronggusses == 3)
	{
		std::cout << endl << endl
			<< "   +----+  " << endl
			<< "   |    |  " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else if (wronggusses == 2)
	{
		std::cout << endl << endl
			<< "   +----+  " <<endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else if (wronggusses == 1)
	{
		std::cout << endl << endl
			<< "   +       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "   |       " << endl
			<< "  =============" << endl << endl;
	}
	else {};
}
void hangman::letter(string input, char from, char to)
{
	string s;
	for (char i = from; i <= to; i++)
	{

		if (input.find(i) == string::npos) //didn't find char
		{
			s += i;
			s += " ";
		}
		else
		{
			s += " ";
		}
	}
	massege(s,false,false);
}
void hangman::avilableletters(string del)
{
	letter(del, 'A', 'M');
    letter(del, 'N', 'Z');
}
bool hangman::printword(string word, string gussed)
{
	bool won = true;
	string x;
	for (int i = 0; i < word.length(); i++)
	{
		if (gussed.find(word[i]) == string::npos)
		{
			won = false;
			x += " _ ";
		}
		else
		{
			x += word[i];
			x += " ";
		}
	}
	massege(x);
	return won;
}
int hangman::trails(string word, string gussed)
{
	int wrong = 0;
	for (int i = 0; i < gussed.length(); i++)
	{
		if (word.find(gussed[i]) == string::npos)
			wrong++;
	}
	return wrong;
}
string hangman::randomword(string category, int lo, int hi)
{
	category += ".txt";
	int line = 0;
	string word;
	vector<string>v;
	ifstream reader(category);
	if (reader.is_open())
	{
		while (std::getline(reader, word))
		{
			if (lo <= word.size() && word.size() <= hi)
				v.push_back(word);
		}
		int random = rand() % v.size();  //from 0 to end of lines
		word = v.at(random);
		reader.close();
	}
	for (int i = 0; i < word.size(); ++i)
		word[i] = toupper(word[i]);
	return word;
}

void hangman::startGame() {
	string anyword;
	char ch1;
	cout << "choose category" << endl;
	cin >> ch1;
	string ch2;
	cin >> ch2;
	string category = getRandomCategory();
	if (ch1 == 'M')
	{
		category = "movies";
	}
	if (ch1 == 'C')
	{
		category = "countries";
	}
	if (ch1 == 'F')
	{
		category = "fruit";
	}
	if (ch1 == 'J')
	{
		category = "jobs";
	}
	if (ch1 == 'A')
	{
		category = "animals";
	}
	int lo, hi;
	if (ch2 == "Easy"){
		lo = 1, hi = 4;
	}
	if (ch2 == "Medium"){
		lo = 5, hi = 7;
	}
	if (ch2 == "Hard"){
		lo = 8, hi = 1000;
	}
	anyword = randomword(category, lo, hi); 
	play(anyword, category);
}

void hangman::play(string word, string category) {
	string gusses;
	int tries = 0;
	bool win = false;
	do 
	{
		system("cls");
		cout << word << endl;
		massege("\tHANG MAN\n\t" + category, false, false);
		cout << endl;
		avilableletters(gusses);
		cout << endl;
		massege("  Guess the word", false, false);
		drawhangman(tries);
		win = printword(word, gusses);
		if (win == true)
			break; // todo: bta3
		char x;
		cout << ">"; cin >> x;
		x = toupper(x);
		if (gusses.find(x) == string::npos)
			gusses += x;
		tries = trails(word, gusses);
	} while (tries < 9);
	
	if (win)
	{
		cout << "        you won" << endl;
	}
	else
		cout << "        game over" << endl;
	getchar();
}
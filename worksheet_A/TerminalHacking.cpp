// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game
	
	string guessedWord;
	int likeness = 0;
	int guesses = 0;
	
	//<------------------------------------------------------------
	//Probably won't work here but is working code.
	cout << "\nHow many letters do you want per word? 4-7\n";
    	cin>>opt; //Fetches user response
         
         switch (opt) //selection statement - option
         {
                case '4': //Condition
                      wordLength = 4;//Changes variable controlling word length
                     break; //Stops conditions overlapping
                case '5':
                     wordLength = 5;
                     break;
                case '6':
                     wordLength = 6;
                     break;
                case '7':
                     wordLength = 7;
                     break;

	//------------------------------------------------------------>

	while (guesses < 4)
	{
		cout << "\nPlease enter your guessed word in all capitals.:\n";
		cin >> guessedWord;

		set<string>iterator i = options.find(guessedWord);
		if (i == options.end())
		{
		cout << "Invalid Guess." << endl;
		continue;
		}
		else
		{
			cout << "\nCalculating Score.\n";
		}

		likeness = getLikeness(guessedWord, secret);
		cout << "\nScore: " << likeness << " out of " << wordLength << "\n";

		if (likeness == wordLength)
		{
			cout << "\nYou guessed correctly!\n";
			exit(0);
		}

		else
		{
			guesses++;
			cout << "\nYou have " << 4 - guesses << " guesses remaining. \n";
			likeness = 0;
		}

	}

	cout << "\nYou lose!\n";

  return 0;
}

/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int32;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;		//INSTATING NEW GAME

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	std::cout << std::endl;
	return 0;
}

void PrintIntro()
{
	//INTRO
	constexpr int32 WORD_LENGTH = 5;
	system("cls"); //CLEARS CONSOLE
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//GET PLAYER GUESS
	FText Guess = "";
	std::cout << std::endl;
	std::cout << "Try " << CurrentTry << ". " <<"Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText response = "";
	std::getline(std::cin, response);

	return (response[0] == 'y' || response[0] == 'Y');
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	// TODO CHANGE FROM FOR TO WHILE LOOP ONCE WE ARE VALIDATING TRIES
	//LOOP ASKER FOR GUESS
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();		//TODO MAKE LOOP CHECKING IF VALID

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO GET GAME SUMMARY
}
}
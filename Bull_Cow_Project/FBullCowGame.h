#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// VALUES INT. TO ZERO
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); //CONSTRUCTOR

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); //TODO RETURN BETTER VALUE
	void Reset(); //TODO CHANGE FROM VOID

	FBullCowCount SubmitGuess(FString);

//PLEASE IGNORE ME
private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 8;

	FString MyHiddenWord = "planet";
};
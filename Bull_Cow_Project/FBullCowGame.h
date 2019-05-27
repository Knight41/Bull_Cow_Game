#pragma once
#include <string>

using FString = std::string;
using int32 = int;


class FBullCowGame
{
public:
	FBullCowGame(); //CONSTRUCTOR

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); //TODO RETUNR BETTER VALUE
	void Reset(); //TODO CHANGE FROM VOID

//PLEASE IGNORE ME
private:
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 8;

};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"
struct BullAndCow
{
	int32 Bull = 0;
	int32 Cow = 0;
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	void SetWordlist();
	void EndGame();
	void GameProcess(const FString& UserGuess);
	bool IsIosgram(const FString& Guess) const;
	TArray<FString> GetIosgramList(const TArray<FString>& wordlist);
	BullAndCow GetBullAndCow(const FString& UserGuess) const;
	

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 life;
		bool bGameOver;
		TArray<FString> Word;
		TArray<FString> Wordlist;
	
};

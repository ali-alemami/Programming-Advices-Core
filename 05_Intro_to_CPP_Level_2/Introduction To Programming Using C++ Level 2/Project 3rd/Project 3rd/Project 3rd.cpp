#include <iostream>
using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enChoice PlayerChoice;
	enChoice ComputerChoice;
	enWinner RoundWinner;
	string RoundWinnerName = "";
};

struct stGameResults
{
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner FinalWinner;
	string FinalWinnerName = "";
};

int ReadHowManyRounds()
{
	int Number = 0;
	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

string TypeChoiceName(enChoice Choice)
{
	string arrChoiceName[3] = { "Rock", "Paper", "Scissors" };
	return arrChoiceName[Choice - 1];
}

string TypeWinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player","Computer","Draw" };
	return arrWinnerName[Winner - 1];
}

enChoice ReadPlayerChoice()
{
	int Choice = 0;
	do
	{
		cout << "Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);	
	return enChoice(Choice);
}

enChoice GetComputerChoice()
{
	return enChoice(RandomNumber(1, 3));
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	default:
		system("color 6F");
	}
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}
	switch (RoundInfo.PlayerChoice)
	{
	case enChoice::Rock:
		if (RoundInfo.ComputerChoice == enChoice::Scissors)
		{
			return enWinner::Player;
		}
	case enChoice::Paper:
		if (RoundInfo.ComputerChoice == enChoice::Rock)
		{
			return enWinner::Player;
		}
	case enChoice::Scissors:
		if (RoundInfo.ComputerChoice == enChoice::Paper)
		{
			return enWinner::Player;
		}
	}
	return enWinner::Computer;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{

	cout << "__________Round [" << RoundInfo.RoundNumber << "]__________\n\n";

	cout << "Player Choice  : " << TypeChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << TypeChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : " << RoundInfo.RoundWinnerName << endl;

	cout << "\n______________________________\n\n";

	SetWinnerScreenColor(RoundInfo.RoundWinner);
}

enWinner WhoWonTheGame(stGameResults GameResults)
{
	if (GameResults.PlayerWinTimes == GameResults.ComputerWinTimes)
	{
		return enWinner::Draw;
	}
	else if (GameResults.PlayerWinTimes > GameResults.ComputerWinTimes)
	{
		return enWinner::Player;
	}
	else
		return enWinner::Computer;
}

stGameResults FillGameResults(short GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.PlayerWinTimes = PlayerWinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.FinalWinner = WhoWonTheGame(GameResults);
	GameResults.FinalWinnerName = TypeWinnerName(GameResults.FinalWinner);

	return GameResults;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

string  Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.FinalWinnerName << endl;
	cout << Tabs(2) << "___________________________________________________________\n";
	SetWinnerScreenColor(GameResults.FinalWinner);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\n\nRound [" << GameRound << "] begins:\n\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.RoundWinnerName = TypeWinnerName(RoundInfo.RoundWinner);


		if (RoundInfo.RoundWinner == enWinner::Player)
		{
			PlayerWinTimes++;
		}
		else if (RoundInfo.RoundWinner == enWinner::Computer)
		{
			ComputerWinTimes++;
		}
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
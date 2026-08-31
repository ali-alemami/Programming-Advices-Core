#include <iostream>
using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	int RoundNumber = 0;
	enChoice Player1Choice;
	enChoice ComputerChoice;
	enWinner RoundWinner;
	string RoundWinnerName = "";
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner Winner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadHowManyRounds()
{
	int Number = 0;
	do
	{
		cout << "How Many Rounds From 1 to 10 ? " << endl;
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}

enChoice ReadPlayer1Choice()
{
	int Number = 0;
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Number;
	} while (Number < 1 || Number > 3);
	return (enChoice)Number;
}

enChoice GetComputerChoice()
{
	return enChoice(RandomNumber(1, 3));
}

string TypeChoiceName(enChoice Choice)
{
	string arrGameChoice[3] = { "Rock", "Paper", "Scissors" };
	return arrGameChoice[Choice - 1];
}

string TypeWinnerName(enWinner Winner)
{
	string arWinnerName[3] = { "Player1", "Computer", "No Winner" };
	return arWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}
	switch (RoundInfo.Player1Choice)
	{
	case enChoice::Rock:
		if (RoundInfo.ComputerChoice == enChoice::Scissor)
		{
			return enWinner::Player;
		}
	case enChoice::Paper:
		if (RoundInfo.ComputerChoice == enChoice::Rock)
		{
			return enWinner::Player;
		}
	case enChoice::Scissor:
		if (RoundInfo.ComputerChoice == enChoice::Paper)
		{
			return enWinner::Player;
		}
	}
	return enWinner::Computer;
}

void SetWinnerScreenColor(enWinner Winner)
{
	if (Winner == enWinner::Player)
		system("color 2f");
	else if (Winner == enWinner::Computer)
	{
		system("color 4f");
		cout << "\a";
	}
	else
		system("color 6f");
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n\n__________Round [1]__________\n\n";

	cout << "Player1 Choice: " << TypeChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << TypeChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner: " << RoundInfo.RoundWinnerName << endl;
	cout << "____________________________________\n\n";

	SetWinnerScreenColor(RoundInfo.RoundWinner);
}

enWinner WhoWonTheGame(stGameResults GameResults)
{
	if (GameResults.Player1WinTimes == GameResults.ComputerWinTimes)
	{
		return enWinner::Draw;
	}
	else if (GameResults.Player1WinTimes > GameResults.ComputerWinTimes)
	{
		return enWinner::Player;
	}
	else
		return enWinner::Computer;
}

string tabs(int Number)
{
	string tabs = "";
	for (int i = 1; i <= Number; i++)
	{
		tabs += "\t";
	}
	return tabs;
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

stGameResults FillGameResults(short HowManyRounds, short Player1WinTmes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResult;

	GameResult.GameRounds = HowManyRounds;
	GameResult.Player1WinTimes = Player1WinTmes;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.Winner = WhoWonTheGame(GameResult);
	GameResult.WinnerName = TypeWinnerName(GameResult.Winner);

	return GameResult;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;

	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.RoundWinnerName = TypeWinnerName(RoundInfo.RoundWinner);

		if (RoundInfo.RoundWinner == enWinner::Player)
			Player1WinTimes++;
		else if(RoundInfo.RoundWinner == enWinner::Computer)
			ComputerWinTimes++;
		else DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

void PrintGameOverScreen()
{
	cout << tabs(3) << "____________________________________________________________\n\n";
	cout << tabs(5) << "+ + + G A M E O V E R + + + \n\n";
	cout << tabs(3) << "____________________________________________________________\n\n";
}

void PrintGameResultScreen(stGameResults GameResults)
{
	cout << tabs(3) << "_____________________ [GAME RESULTS]________________________\n\n";
	cout << tabs(3) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << tabs(3) << "Player1 Win Times  : " << GameResults.Player1WinTimes << endl;
	cout << tabs(3) << "Computer Win Times : " << GameResults.ComputerWinTimes << endl;
	cout << tabs(3) << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << tabs(3) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << tabs(3) << "__________________________________________________________\n\n";
}

void StartGame()
{
	char PlayAgain = 'Y';
	
	do
	{
		ResetScreen();
		stGameResults GameResult = PlayGame(ReadHowManyRounds());
		PrintGameOverScreen();
		PrintGameResultScreen(GameResult);

		cout << endl << tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
} 
#include <iostream>
using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	int RoundNumber = 0;
	enChoice PlayerChoice;
	enChoice ComputerChoice;
	enWinner RoundWinner;
	string RoundWinnerName = "";
};

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

enChoice ReadPlayerChoice()
{
	int Number = 0;
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Number;
	} while (Number < 1 || Number > 3);
	return (enChoice)Number;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enChoice GetComputerChoice()
{
	return enChoice(RandomNumber(1, 3));
}

string TypeChoiceName(enChoice Choice)
{
	switch (Choice)
	{
	case Rock:
		return "Rock";
	case Paper:
		return "Paper";
	case Scissor:
		return "Scissors";
	}
}

string TypeWinnerName(enWinner Winner)
{
	switch (Winner)
	{
	case Player:
		return "Player";
	case Computer:
		return "Computer";
	case Draw:
		return "[No Winner]";
	}
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		RoundInfo.RoundWinner = enWinner::Draw;
	}
	else
	{
		if (RoundInfo.PlayerChoice == enChoice::Rock && RoundInfo.ComputerChoice == enChoice::Scissor)
			RoundInfo.RoundWinner = enWinner::Player;

		else if (RoundInfo.PlayerChoice == enChoice::Paper && RoundInfo.ComputerChoice == enChoice::Rock)
			RoundInfo.RoundWinner = enWinner::Player;

		else if (RoundInfo.PlayerChoice == enChoice::Scissor && RoundInfo.ComputerChoice == enChoice::Paper)
			RoundInfo.RoundWinner = enWinner::Player;

		else
			RoundInfo.RoundWinner = enWinner::Computer;
	}
	return RoundInfo.RoundWinner;
}

void ChangeScreenColor(enWinner Winner)
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

stRoundInfo PlayRound(int RoundNumber)
{
	stRoundInfo RoundInfo;

	
		cout << "Round [" << RoundNumber << "] begins:\n\n";

		RoundInfo.RoundNumber = RoundNumber;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.RoundWinnerName = TypeWinnerName(RoundInfo.RoundWinner);

		cout << "\n\n__________Round [1]__________\n\n";

		cout << "Player1 Choice: " << TypeChoiceName(RoundInfo.PlayerChoice) << endl;
		cout << "Computer Choice: " << TypeChoiceName(RoundInfo.ComputerChoice) << endl;
		cout << "Round Winner: " << RoundInfo.RoundWinnerName << endl;
		cout << "____________________________________\n\n";

		ChangeScreenColor(RoundInfo.RoundWinner);

		return RoundInfo;
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

void PrintGameOverScreen()
{
	cout << tabs(3) << "____________________________________________________________\n\n";
	cout << tabs(5) << "+ + + G A M E O V E R + + + \n\n";
	cout << tabs(3) << "____________________________________________________________\n\n";
}

struct stGameInfo
{
	int GameRounds = 0;
	int Player1WinTimes = 0;
	int ComputrerWinTimes = 0;
	int DrawTimes = 0;
	enWinner FinalWinner;
	string FinalWinnerName = "";
};

void PrintGameResultScreen(stGameInfo GameInfo)
{
	cout << tabs(3) << "_____________________ [GAME RESULTS]________________________\n\n";
	cout << tabs(3) << "Game Rounds        : " << GameInfo.GameRounds << endl;
	cout << tabs(3) << "Player1 Win Times  : " << GameInfo.Player1WinTimes << endl;
	cout << tabs(3) << "Computer Win Times : " << GameInfo.ComputrerWinTimes << endl;
	cout << tabs(3) << "Draw Times         : " << GameInfo.DrawTimes << endl;
	cout << tabs(3) << "Final Winner       : " << GameInfo.FinalWinnerName << endl;
	cout << tabs(3) << "__________________________________________________________\n\n";
}

enWinner WhoWonTheGame(stGameInfo GameInfo)
{
	if (GameInfo.Player1WinTimes == GameInfo.ComputrerWinTimes)
	{
		return enWinner::Draw;
	}
	else if (GameInfo.Player1WinTimes > GameInfo.ComputrerWinTimes)
	{
		return enWinner::Player;
	}
	else
		return enWinner::Computer;
}

void StartGame()
{
	stGameInfo GameInfo;

	GameInfo.GameRounds = ReadHowManyRounds();

	GameInfo.Player1WinTimes = 0, GameInfo.ComputrerWinTimes = 0, GameInfo.DrawTimes = 0;

	for (int i = 1; i <= GameInfo.GameRounds; i++)
	{
		stRoundInfo RoundInfo = PlayRound(i);

		
			if (RoundInfo.RoundWinner == enWinner::Player)
				GameInfo.Player1WinTimes++;
			else if (RoundInfo.RoundWinner == enWinner::Computer)
				GameInfo.ComputrerWinTimes++;
			else
				GameInfo.DrawTimes++;
	}

	GameInfo.FinalWinner = WhoWonTheGame(GameInfo);
	GameInfo.FinalWinnerName = TypeWinnerName(GameInfo.FinalWinner);


	PrintGameOverScreen();
	PrintGameResultScreen(GameInfo);

}

void PlayGame()
{
	char PlayAgain = 'y';

	do
	{
		system("cls");
		system("color 0f");

		StartGame();

		cout << "Do you want to play again ? Y/N ?";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	PlayGame();
}
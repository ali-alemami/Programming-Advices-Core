#include <iostream>
using namespace std;

enum enQuizzLvl { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };

struct stRoundInfo
{
	int QuestionNumber = 0;
	enQuizzLvl QuizzLvl;
	enOpType OpType;
	int Number1 = 0;
	int Number2 = 0;
	int Result = 0;
	int PlayerResult = 0;
};

struct stGameInfo
{
	int NumberOfQuesions = 0;
	enQuizzLvl QuizzLvl;
	enOpType OpType;
	int NumberOfRightAnswers = 0;
	int NumberOfWrongAnswers = 0;
};

int AskHowManyQuestion()
{
	int Number = 0;

	do
	{
		cout << "How Many Questions Do You Want To Answer ? ";
		cin >> Number;

	} while (Number < 1 || Number > 10);
	return Number;
}

enQuizzLvl AskQuizzLvl()
{
	int Number = 0;

	do
	{
		cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 4);

	return enQuizzLvl(Number);
}

enOpType AskOpType()
{
	int Number = 0;

	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 5);

	return enOpType(Number);
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int RandomQuestionNumber(enQuizzLvl QuizzLvl)
{
	switch (QuizzLvl)
	{
	case Easy:
		return RandomNumber(1, 10);
	case Med:
		return RandomNumber(11, 20);
	case Hard:
		return RandomNumber(20, 100);
	case Mix:
		return RandomNumber(1, 100);
	}
}

char GetOpChar(enOpType OpType)
{
	char Op[5] = { '+', '-', '*', '/' };
	return Op[OpType - 1];
}

void PrintRoundInfo(stRoundInfo RoundInfo)
{

	cout << RoundInfo.Number1 << endl;
	cout << RoundInfo.Number2 << "  ";
	cout << GetOpChar(RoundInfo.OpType) << endl;
	cout << "\n___________________\n";
}

int QuizzAnswer(stRoundInfo RoundInfo)
{
	switch (RoundInfo.OpType)
	{
	case Add:
		return RoundInfo.Number1 + RoundInfo.Number2;
	case Sub:
		return RoundInfo.Number1 - RoundInfo.Number2;
	case Mul:
		return RoundInfo.Number1 * RoundInfo.Number2;
	case Div:
		return RoundInfo.Number1 / RoundInfo.Number2;
	}
}

enOpType GetRandomOpType()
{
	int Number = RandomNumber(1, 4);
	return enOpType(Number);
}

void SetScreenColor(stRoundInfo RoundInfo)
{
	if (RoundInfo.Result == RoundInfo.PlayerResult)
		system("color 2f");
	else
		system("color 4f");
}

stGameInfo StartGame()
{
	stGameInfo GameInfo;
	stRoundInfo RoundInfo;

	GameInfo.NumberOfQuesions = AskHowManyQuestion();
	GameInfo.QuizzLvl = AskQuizzLvl();
	GameInfo.OpType = AskOpType();

	for (RoundInfo.QuestionNumber = 1; RoundInfo.QuestionNumber <= GameInfo.NumberOfQuesions; RoundInfo.QuestionNumber++)
	{
		cout << "Question [" << RoundInfo.QuestionNumber << "]\n\n";

		RoundInfo.Number1 = RandomQuestionNumber(GameInfo.QuizzLvl);
		RoundInfo.Number2 = RandomQuestionNumber(GameInfo.QuizzLvl);

		if (GameInfo.OpType == enOpType::OpMix)
			RoundInfo.OpType = GetRandomOpType();
		else
			RoundInfo.OpType = GameInfo.OpType;

		RoundInfo.QuizzLvl = GameInfo.QuizzLvl;

		RoundInfo.Result = QuizzAnswer(RoundInfo);

		PrintRoundInfo(RoundInfo);

		cin >> RoundInfo.PlayerResult;

		if (RoundInfo.Result == RoundInfo.PlayerResult)
		{
			cout << "Right Answer :-)\n\n";
			GameInfo.NumberOfRightAnswers++;
		}
		else
		{
			cout << "Wrong Answer :-(\n\n";
			cout << "The Right Answer is: " << RoundInfo.Result << endl;
			GameInfo.NumberOfWrongAnswers++;
		}

		SetScreenColor(RoundInfo);
	}
	return GameInfo;
}

void PrintGameOverScreen(stGameInfo GameInfo)
{
	cout << "\n\n______________________________\n\n";

	if (GameInfo.NumberOfRightAnswers >= GameInfo.NumberOfWrongAnswers)
		cout << "FINAL RESULT IS PASS";
	else
		cout << "FINAL RESULT IS FAIL";

	cout << "\n\n______________________________\n\n";
}

string GetQuizzLvlString(enQuizzLvl QuizzLvl)
{
	string QuizLvl[4] = { "Easy", "Med", "Hard", "Mix" };
	return QuizLvl[QuizzLvl - 1];
}

string GetOpString(enOpType OpType)
{
	string Op[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
	return Op[OpType - 1];
}

void PrintGameInfo(stGameInfo GameInfo)
{
	cout << "Number Of Question: " << GameInfo.NumberOfQuesions << endl;
	cout << "Questions Level   : " << GetQuizzLvlString(GameInfo.QuizzLvl) << endl;
	cout << "Op Type           : " << GetOpString(GameInfo.OpType) << endl;
	cout << "Number of right answers: " << GameInfo.NumberOfRightAnswers << endl;
	cout << "Number of wring answers: " << GameInfo.NumberOfWrongAnswers << endl;
}

void ResetScreen()
{
	system("color 0f");
	system("cls");
}

void PlayGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameInfo GameInfo = StartGame();
		PrintGameOverScreen(GameInfo);
		PrintGameInfo(GameInfo);

		cout << "Do you want to play again (Y/N) ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

	ResetScreen();
}

int main()
{
	srand((unsigned)time(NULL));

	PlayGame();

	return 0;
}
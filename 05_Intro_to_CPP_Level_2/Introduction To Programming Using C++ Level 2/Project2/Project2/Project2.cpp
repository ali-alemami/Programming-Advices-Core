#include <iostream>
using namespace std;

enum enQuesionLvl { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };

struct stQuizzInfo
{
	int Number1 = 0;
	int Number2 = 0;
	enQuesionLvl QuessionLvl;
	enOpType OpType;
	int PlayerResult = 0;
	int Result = 0;
};

struct stGameResults
{
	int NumberOfQuestions = 0;
	enQuesionLvl QuestionsLvl;
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

	} while (Number < 1 && Number > 10);
	return Number;
}

enQuesionLvl AskQuestionLvl()
{
	int QuestionLvl = 0;

	cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	cin >> QuestionLvl;

	return enQuesionLvl(QuestionLvl);
}

enOpType AskOpType()
{
	int OpType = 0;

	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
	cin >> OpType;

	return enOpType(OpType);
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int RandomQuestionNumber(enQuesionLvl QuestionLevel)
{
	switch (QuestionLevel)
	{
	case Easy:
		return RandomNumber(1, 10);
	case Medium:
		return RandomNumber(11, 20);
	case Hard:
		return RandomNumber(20, 100);
	case Mix:
		return RandomNumber(1, 100);
	}
}

int QuestionResult(int Number1, int Number2, enOpType OpType)
{
	switch (OpType)
	{
	case Add:
		return Number1 + Number2;
	case Sub:
		return Number1 - Number2;
	case Mul:
		return Number1 * Number2;
	case Div:
		return Number1 / Number2;
	}
}

char OpTypeToChar(enOpType OpType)
{
	switch (OpType)
	{
	case Add:
		return '+';

	case Sub:
		return '-';

	case Mul:
		return '*';

	case Div:
		return '/';
	}
}

stQuizzInfo SaveQuizzInfo(enQuesionLvl QuestionLevel, enOpType OpType)
{
	stQuizzInfo QuizzInfo;

	QuizzInfo.Number1 = RandomQuestionNumber(QuestionLevel);
	QuizzInfo.Number2 = RandomQuestionNumber(QuestionLevel);
	QuizzInfo.QuessionLvl = QuestionLevel;
	QuizzInfo.OpType = OpType;
	QuizzInfo.Result = QuestionResult(QuizzInfo.Number1, QuizzInfo.Number2, OpType);

	return QuizzInfo;
}

void PrintQuizzInfo(stQuizzInfo& QuizzInfo)
{

	cout << QuizzInfo.Number1 << endl;
	cout << QuizzInfo.Number2 << "  ";
	cout << OpTypeToChar(QuizzInfo.OpType) << endl;
	cout << "\n________________________\n";
	cin >> QuizzInfo.PlayerResult;
}

void SetScreenColor(stQuizzInfo QuizzInfo)
{
	if (QuizzInfo.PlayerResult == QuizzInfo.Result)
	{
		system("color 2f");
	}
	else
		system("color 4f");
}

stGameResults StartGame()
{
	stGameResults GameResults;

	GameResults.NumberOfQuestions = AskHowManyQuestion();
	GameResults.QuestionsLvl = AskQuestionLvl();
	GameResults.OpType = AskOpType();

	for (int QuestionNumber = 1; QuestionNumber <= GameResults.NumberOfQuestions; QuestionNumber++)
	{
		stQuizzInfo QuizzInfo = SaveQuizzInfo(GameResults.QuestionsLvl, GameResults.OpType);

		if (GameResults.OpType == enOpType::OpMix)
		{
			QuizzInfo.OpType = enOpType(RandomNumber(1, 4));
			QuizzInfo.Result = QuestionResult(QuizzInfo.Number1, QuizzInfo.Number2, QuizzInfo.OpType);
		}

		cout << "Question [" << QuestionNumber << "/" << GameResults.NumberOfQuestions << "]\n\n";

		
		PrintQuizzInfo(QuizzInfo);

		if (QuizzInfo.PlayerResult == QuizzInfo.Result)
		{

			cout << "Right Answer :-)\n\n";
			SetScreenColor(QuizzInfo);
			
			GameResults.NumberOfRightAnswers++;
		}
		else
		{
			SetScreenColor(QuizzInfo);
			cout << "Wrong Answer :-(\n";
			cout << "The Right Answer: " << QuizzInfo.Result << endl << endl;
			GameResults.NumberOfWrongAnswers++;
		}

	}

	return GameResults;
}

void PrintGameOverScreen(stGameResults GameResults)
{
	cout << "\n\n______________________________\n\n";

	if (GameResults.NumberOfRightAnswers >= GameResults.NumberOfWrongAnswers)
	{
		cout << "FINAL RESULT IS PASS :-)";
	}
	else
	{
		cout << "FINAL RESULT IS FAIL :-)";
	}
	cout << "\n\n______________________________\n\n";
}

string PrintOpType(enOpType OpType)
{
	string Op[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
	return Op[OpType - 1];
}

string PrintQuestionLvl(enQuesionLvl QuestionLvl)
{
	string QuizzLvl[4] = { "Easy", "Med", "Hard", "Mix" };
	return QuizzLvl[QuestionLvl - 1];
}

void ShowGameResults(stGameResults GameResults)
{
	cout << "Number Of Questions: " << GameResults.NumberOfQuestions << endl;
	cout << "Questions Level    : " << PrintQuestionLvl(GameResults.QuestionsLvl) << endl;
	cout << "Op Type            : " << PrintOpType(GameResults.OpType) << endl;
	cout << "Number of right answers: " << GameResults.NumberOfRightAnswers << endl;
	cout << "Number of wrong answers: " << GameResults.NumberOfWrongAnswers << endl;
	cout << "\n\n______________________________\n\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void PlayGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();

		stGameResults GameResults = StartGame();
		PrintGameOverScreen(GameResults);
		ShowGameResults(GameResults);

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
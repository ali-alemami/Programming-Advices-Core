#include <iostream>
using namespace std;

enum enLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enLevel QuestionLvl;
	enOpType QuestionOpType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enLevel QuizzLvl;
	enOpType QuizzOpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

int AskHowManyQuestions()
{
	int Number = 0;
	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}

enLevel AskQuestionLvl()
{
	int Number = 0;
	do
	{
		cout << "Enter Question Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 4);
	return enLevel(Number);
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

int SimpleCalculator(int Number1, int Number2, enOpType OpType)
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
	default:
		return Number1 + Number2;
	}
}

stQuestion GenerateQuestion(enLevel QuizzLvl, enOpType QuizzOpType)
{
	stQuestion Question;

	if (QuizzLvl == enLevel::Mix)
	{
		QuizzLvl = enLevel(RandomNumber(1, 3));
	}

	if (QuizzOpType == enOpType::OpMix)
	{
		QuizzOpType = enOpType(RandomNumber(1, 4));
	}

	Question.QuestionOpType = QuizzOpType;

	switch (QuizzLvl)
	{
	case Easy:

		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.QuestionOpType);
		Question.QuestionLvl = QuizzLvl;
		return Question;
		
	case Medium:

		Question.Number1 = RandomNumber(11, 20);
		Question.Number2 = RandomNumber(11, 20);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.QuestionOpType);
		Question.QuestionLvl = QuizzLvl;
		return Question;

	case Hard:
		Question.Number1 = RandomNumber(21, 100);
		Question.Number2 = RandomNumber(21, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.QuestionOpType);
		Question.QuestionLvl = QuizzLvl;
		return Question;
	}
	return Question;
}

void GenerateQuestions(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuizzLvl, Quizz.QuizzOpType);
	}
}

string GetOpSymbol(enOpType OpType)
{
	switch (OpType)
	{
	case Add:
		return "+";
	case Sub:
		return "-";
	case Mul:
		return "*";
	case Div:
		return "/";
	case OpMix:
		return "Mix";
	}
}

string GetQuizzLvlText(enLevel Level)
{
	string arrLevel[4] = { "Easy", "Medium", "Hard", "Mix" };
	return arrLevel[Level - 1];
}

void PrintTheQuestion(stQuizz Quizz, short QuestionNumber)
{
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << "  ";
	cout << GetOpSymbol(Quizz.QuestionList[QuestionNumber].QuestionOpType) << endl << endl;
	cout << "__________\n";
}

int ReadPlayerAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void SetScreenColor(bool IsRight)
{
	if (IsRight)
	{
		system("color 2f");
	}
	else
	{
		system("color 4f");
	}
}

void CorrectQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer == Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;
		cout << "Right Answer :-)\n\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;
		cout << "Wrong Answer :_;\n";
		cout << "The Right Answer is " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl << endl;
	}

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		PrintTheQuestion(Quizz, Question);
		Quizz.QuestionList[Question].PlayerAnswer = ReadPlayerAnswer();
		CorrectQuestionAnswer(Quizz, Question);
	}
	
	Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string GetQuizzResult(bool IsPass)
{
	if (IsPass)
	{
		return "PASS :-)";
	}
	else
	{
		return "Fail :_;";
	}
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "______________________________________________________\n\n";
	cout << "Final Result is " << GetQuizzResult(Quizz.IsPass);
	cout << "\n\n______________________________________________________\n\n";


	cout << "Number Of Questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuizzLvlText(Quizz.QuizzLvl) << endl;
	cout << "Operation Type     : " << GetOpSymbol(Quizz.QuizzOpType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;

	cout << "______________________________________________________\n\n";

}

void StartGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = AskHowManyQuestions();
	Quizz.QuizzLvl = AskQuestionLvl();
	Quizz.QuizzOpType = AskOpType();

	GenerateQuestions(Quizz);
	AskAndCorrectQuestionListAnswer(Quizz);
	PrintQuizzResults(Quizz);
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
		StartGame();

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
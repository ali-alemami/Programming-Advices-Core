#include <iostream>
using namespace std;


enum enQuizzLvl { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };

struct stQuestion
{
	short Number1 = 0;
	short Number2 = 0;
	enQuizzLvl QuestionLvl;
	enOpType QuestionOpType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuesions = 0;
	enQuizzLvl QuizzLvl;
	enOpType QuizzOpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

short AskHowManyQuestion()
{
	short Number = 0;
	do
	{
		cout << "How Many Question do you want to answer ? ";
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}

enQuizzLvl AskQuizzLvl()
{
	short Number = 0;
	do
	{
		cout << "Enter questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 4);
	return enQuizzLvl(Number);
}

enOpType AskOpType()
{
	short Number = 0;
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
	case Medium:
		return RandomNumber(11, 20);
	case Hard:
		return RandomNumber(20, 100);
	}
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
	}
}

stQuestion GenerateQuestion(enQuizzLvl QuestionLvl, enOpType OpType)
{
	stQuestion Question;

	if (QuestionLvl == enQuizzLvl::Mix)
	{
		QuestionLvl = enQuizzLvl(RandomNumber(1, 3));
	}
	
	if (OpType == enOpType::OpMix)
	{
		OpType = enOpType(RandomNumber(1, 4));
	}

	Question.QuestionOpType = OpType;
	Question.QuestionLvl = QuestionLvl;

	Question.Number1 = RandomQuestionNumber(Question.QuestionLvl);
	Question.Number2 = RandomQuestionNumber(Question.QuestionLvl);
	Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.QuestionOpType);

	return Question;
}

void GenerateQuestions(stQuizz& Quizz)
{
	for (int QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuesions; QuestionNumber++)
	{
		Quizz.QuestionList[QuestionNumber] = GenerateQuestion(Quizz.QuizzLvl, Quizz.QuizzOpType);
	}
}

string GetOpTypeSymbol(enOpType OpType)
{
	switch (OpType)
	{ 
	case enOpType::Add:
		return"+";
	case enOpType::Sub:
		return"-";
	case enOpType::Mul:
		return"x";
	case enOpType::Div:
		return"/";
	default:
		return"Mix";
	}
}

void PrintQuestion(stQuizz Quizz, short QuestionNumber)
{
	cout << "Question [" << QuestionNumber << "/" << Quizz.NumberOfQuesions << "]\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << "  ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].QuestionOpType) << endl;
	cout << "____________________\n";
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

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
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

		cout << "Worng Answer :_; \n";
		cout << "The right answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
	}

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuesions; QuestionNumber++)
	{
		PrintQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string GetFinalResultText(bool Pass)
{
	if (Pass)
		return "PASS :-)";
	else
		return "Fail :-(";
}

string GetQuestionLevelText(enQuizzLvl QuestionLevel)	
{
	string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevelText[QuestionLevel - 1]; }

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "______________________________\n\n";
	cout << " Final Resutls is " << GetFinalResultText(Quizz.IsPass);
	cout << "\n______________________________\n\n";
	cout << "Number of Questions: " << Quizz.NumberOfQuesions << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuizzLvl) << endl;
	cout << "OpType             : " << GetOpTypeSymbol(Quizz.QuizzOpType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "______________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuesions = AskHowManyQuestion();
	Quizz.QuizzLvl = AskQuizzLvl();
	Quizz.QuizzOpType = AskOpType();

	GenerateQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
} 

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLetter = 1, CaptialLetter = 2,
	SpecialCharcater = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122)); 

	case enCharType::CaptialLetter:
		return char(RandomNumber(65, 90));

	case enCharType::SpecialCharcater:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
	cout << GetRandomCharacter(enCharType::CaptialLetter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharcater) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;
	
	return 0;
}
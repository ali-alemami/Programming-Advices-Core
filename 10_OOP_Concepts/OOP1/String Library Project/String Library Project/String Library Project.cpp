#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString S1;

	clsString S2("Ali alaa alemame");

	S1.Value = " mohammad Abu-Hadhoud";

	cout << "String1 = " << S1.Value << endl;
	cout << "String2 = " << S2.Value << endl;

	cout << "Number of words for string 1: " << S1.CountWords() << endl;
	cout << "Number of words for string 2: " << S2.CountWords() << endl;

	cout << "Number of words for this string \" this sentence has five words\": " 
		<< clsString::CountWords("this sentence has five words") << endl;

	clsString S3("Hi how are you?");

	cout << "String3 = " << S3.Value << endl;

	cout << "String3 length = " << S3.Length() << endl;

	S3.UpperFirstLetterOfEachWord();
	cout << "String3 after uppering first letter of each word: " << S3.Value << endl;

	S3.LowerFirstLetterOfEachWord();
	cout << "String3 after lowering first letter of each word: " << S3.Value << endl;

	cout << "After invering \'a\': ";
	cout << clsString::InvertLetterCase('a') << endl;

	S3.Value = "AbCdEfG";

	S3.InvertAllLettersCase();
	cout << S3.Value << endl;

	S3.InvertAllLettersCase();
	cout << S3.Value << endl;

	cout << "Capital Letters count: " << clsString::CountCapitalLetters(" D d D vbgSKF   Z") << endl;

	S3.Value = "Welcome to Jordan";
	cout << S3.Value << endl;

	cout << "Capital Letters Count: " << S3.CountCapitalLetters() << endl; 
	cout << "Small Letters Count: " << S3.CountSmallLetters() << endl; 

	cout << "Vowels Count: " << S3.CountVowels() << endl;

	cout << "Letter E count: " << S3.CountSpecificLetter('E', false) << endl;

	cout << "Is Letter Vowel? " << clsString::isVowel('a');
	cout << "Is Letter Vowel? " << clsString::isVowel('w');

	cout << "Words Count: " << S3.CountWords() << endl;

	vector <string> vString;

	vString = S3.Split(" ");

	cout << "\nTokens = " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}

	//TRIMS;

	S3.Value = "     Mohammad Abu-Hadhoud       ";

	cout << "\nString3 = " << S3.Value << endl;
	S3.TrimLeft();
	cout << "\n\nTrim left: " << S3.Value << endl;

	S3.Value = "     Mohammad Abu-Hadhoud       ";
	S3.TrimRight();
	cout << "\n\nTrim right" << S3.Value << "s" << endl;

	//JOINS;

	vString = { "Mohammad", "Faid", "Ali", "Maher" };

	cout << "\n\nJoin String From Vector: \n";
	cout << clsString::JoinString(vString, " ");

	string arrString[] = { "Mohammad", "Faid", "Ali", "Maher" };
	cout << clsString::JoinString(arrString, 4, "#//#") << endl;

	S3.Value = "ALI ALAA ALEMAME";
	cout << S3.Value << endl;

	S3.ReverseWordsInString(" ");
	cout << S3.Value << endl;

	S3.ReplaceWord("ALAA", "Ali", " ", true);
	cout << S3.Value << endl;

	S3.Value = "This is: a sample text, with punctuations.";
	cout << "\n\nString     = " << S3.Value;

	S3.RemovePunctuations();
	cout << "\nRemove Punctuations : " << S3.Value
		<< endl;

	return 0;
}
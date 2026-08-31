#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:

	string _value;

public:

	clsString()
	{
		_value = "";
	}

	clsString(string Value)
	{
		_value = Value;
	}

	void SetValue(string Value)
	{
		_value = Value;
	}
	string GetValue()
	{
		return _value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return _value.length();
	}

	static short CountWords(string S1)
	{
		short pos = 0,
			count = 0;
		string sWord = "",
			delim = " ";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
				count++;

			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			count++;

		return count;
	}
	short CountWords()
	{
		return CountWords(_value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstWord = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstWord)
			{
				S1[i] = toupper(S1[i]);
			}

			isFirstWord = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_value = UpperFirstLetterOfEachWord(_value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstWord = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstWord)
			{
				S1[i] = tolower(S1[i]);
			}

			isFirstWord = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_value = LowerFirstLetterOfEachWord(_value);
	}

	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void UpperAllString()
	{
		_value = UpperAllString(_value);
	}

	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllString()
	{
		_value =  LowerAllString(_value);
	}

	static char InvertLetterCase(char ch1)
	{
		return islower(ch1) ? toupper(ch1) : tolower(ch1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllLettersCase()
	{
		_value = InvertAllLettersCase(_value);
	}

	enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount)
	{
		if (WhatToCount == All)
		{
			return S1.length();
		}

		short counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == SmallLetters && islower(S1[i]))
				counter++;
			if (WhatToCount == CapitalLetters && isupper(S1[i]))
				counter++;
		}
		return counter;
	}
	short CountLetters(enWhatToCount WhatToCount)
	{
		return CountLetters(_value, WhatToCount);
	}

	static short CountCapitalLetters(string S1)
	{
		short counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				counter++;
		}
		return counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_value);
	}

	static short CountSmallLetters(string S1)
	{
		short counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				counter++;
		}
		return counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					counter++;
			}
		}
		return counter;
	}
	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_value, Letter, MatchCase);
	}

	static bool isVowel(char ch1)
	{
		ch1 = tolower(ch1);

		return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'u') || (ch1 == 'i') || (ch1 == 'o'));
	}

	static short CountVowels(string S1)
	{
		short counter = 0;
		for (short i = 0; i < S1.length() - 1; i++)
		{
			if (isVowel(S1[i]))
				counter++;
		}
		return counter;
	}
	short CountVowels()
	{
		return CountVowels(_value);
	}

	static vector <string> Split(string S1, string delim)
	{
		vector <string> vString;
		short pos = 0;
		string sWord = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			//if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1);
		}
		return vString;
	}
	vector <string> Split(string delim)
	{
		return Split(_value, delim);
	}

	static string TrimLeft(string S1)
	{
		/*while (S1[0] == ' ')
		{
			S1.erase(0, 1);
		}*/
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - 1);
			}
		}

		return S1;
	}
	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}

	static string TrimRight(string S1)
	{
		/*S1 = ReverseStringLetters(S1);
		S1 = TrimLeft(S1);
		S1 = ReverseStringLetters(S1);
		return S1;*/

		/*short i = S1.length() - 1;

		while (S1[i] == ' ')
		{
			S1.erase(i, 1);
			if (i != 0)
			{
				i--;
			}
		}*/
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return S1;
	}
	void TrimRight()
	{
		_value = TrimRight(_value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_value = Trim(_value);
	}

	static string JoinString(vector <string> vString, string delim)
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 += s + delim;
		}
		return S1.substr(0, S1.length() - delim.length());
	}
	static string JoinString(string arrString[], short Length, string delim)
	{
		string S1 = "";
		for (short i = 0; i < Length; i++)
		{
			S1 += arrString[i] + delim;
		}
		return S1.substr(0, S1.length() - delim.length());
	}

	static string ReverseWordsInStringUsingVector(string S1, string delim)
	{
		vector <string> vString;
		vString = Split(S1, delim);

		S1 = "";

		/*for (short i = vString.size() - 1; i >= 0; i--)
		{
			S1 += vString[i] + delim;
		}*/
		vector <string> ::iterator iter = vString.end();

		for (string s : vString)
		{
			--iter;
			S1 += *iter + delim;
		}

		return S1.substr(0, S1.length() - delim.length());
	}
	void ReverseWordsInStringUsingVector(string delim)
	{
		_value = ReverseWordsInStringUsingVector(_value, delim);
	}

	static string ReplaceWordInStringUsingVector(string S1, string OldWord, string NewWord, string delim, bool MatchCase = true)
	{
		vector <string> vString = Split(S1, delim);

		if(MatchCase)
		{
			for (string& word : vString)
			{
				if (word == OldWord)
					word = NewWord;
			}
		}
		else
		{
			for (string& word : vString)
			{
				if (LowerAllString(word) == LowerAllString(OldWord))
					word = NewWord;
			}
		}

		return JoinString(vString, delim);
	}
	void ReplaceWordInStringUsingVector(string OldWord, string NewWord, string delim, bool MatchCase = true)
	{
		_value = ReplaceWordInStringUsingVector(_value, OldWord, NewWord, delim, MatchCase);
	}

	static string ReplaceWordInString(string S1, string OldWord, string NewWord, bool MatchCase = true)
	{
		short pos = 0;

		if (MatchCase)
		{
			while ((pos = S1.find(OldWord)) != std::string::npos)
			{
				S1.replace(pos, OldWord.length(), NewWord);
				pos += NewWord.length();
			}
		}

		else
		{
			string LowerS1 = LowerAllString(S1);
			string LowerOldWord = LowerAllString(OldWord);

			while ((pos = S1.find(LowerOldWord)) != std::string::npos)
			{
				S1.replace(pos, OldWord.length(), NewWord);
				LowerS1.replace(pos, OldWord.length(), NewWord);
				pos += NewWord.length();
			}
		}

		return S1;
	}
	void ReplaceWordInString(string OldWord, string NewWord, bool MatchCase = true)
	{
		_value = ReplaceWordInString(_value, OldWord, NewWord, MatchCase);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}
	void RemovePunctuations()
	{
		_value = RemovePunctuations(_value);
	}

	static string ReverseStringLetters(string S1)
	{
		string sword = "";
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			sword += S1[i];
		}
		return sword;
	}
	void ReverseStringLetters()
	{
		_value = ReverseStringLetters(_value);
	}
};
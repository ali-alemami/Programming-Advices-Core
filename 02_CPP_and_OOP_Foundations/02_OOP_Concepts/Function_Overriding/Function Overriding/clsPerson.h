#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:

	int _ID;
	string _FirstName,
		_LastName,
		_Email,
		_Phone;

public:

	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void SetID(int ID)
	{
		_ID = ID;
	}
	int GetID()
	{
		return _ID;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}

	string FullName()
	{
		return _FirstName + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nID       : " << _ID;
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: " << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\nThe following SMS sent successfully to phone: " << _Phone;
		cout << "\n" << TextMessage << endl;
	}

	static void Fun1(clsPerson Person)
	{
		Person.Print();
	}

	void Fun2()
	{
		Fun1(*this);
	}

};


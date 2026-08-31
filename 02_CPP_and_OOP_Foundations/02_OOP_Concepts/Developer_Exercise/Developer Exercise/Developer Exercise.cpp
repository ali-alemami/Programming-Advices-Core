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

	string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "This is Email  sent to the Email " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl << endl;
	}

	void SendSms(string Message)
	{
		cout << "This is sms sent to the phone number " << _Phone << endl;
		cout << "Message: " << Message << endl << endl;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "_________________________\n";
		cout << "ID        : " << _ID << endl;
		cout << "First Name: " << _FirstName << endl;
		cout << "Last Name : " << _LastName << endl;
		cout << "Full Name : " << GetFullName() << endl;
		cout << "Email     : " << _Email << endl;
		cout << "Phone     : " << _Phone << endl;
		cout << "_________________________\n\n";
	}
};

class clsDeveloper : public clsPerson
{
private:

	string _Title,
		_Department,
		_MainProgrammingLanguage;
	float _Salary;

public:

	clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary) 
		: clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	void SetTitle(string Title)
	{
		_Title = Title;
	}
	string GetTitel()
	{
		return _Title;
	}

	void SetDepartment(string Department)
	{
		_Department = Department;
	}
	string GetDepartment()
	{
		return _Department;
	}

	void SetSalary(float Salary)
	{
		_Salary = Salary;
	}
	float GetSalary()
	{
		return _Salary;
	}

	void Print()
	{
		clsPerson::Print();
		cout << "Title: " << _Title << endl;
		cout << "Department: " << _Department << endl;
		cout << "Salary: " << _Salary << endl;
		cout << "This is the override Function\n\n";
	}

};

int main()
{
	clsDeveloper Developer1(1, "Ali", "Alemame", "a@gmail.com", "0780020203", "CEO", "IT", 1000);

	Developer1.Print();

	return 0;
}
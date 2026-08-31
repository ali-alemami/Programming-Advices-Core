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

	void SendEmail(string Subject, string Body)
	{
		cout << "The following message sent successfully to email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl << endl;
	}

	void SendSMS(string Message)
	{
		cout << "The following SMS sent successfully to phone: " << _Phone << endl;
		cout << Message << endl;
	}
};

class clsEmployee : public clsPerson
{
private:

	string _Title;
	string _Department;
	float _Salary;

public:

	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
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
	string GetTitle()
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
};

int main()
{
	clsEmployee Employee1(1, "Ali", "Alemame", "ali@gmail.com", "7800", "CEO", "IT", 1000);

	Employee1.Print();

	cout << "\n" << Employee1.GetTitle() << endl;
	cout << Employee1.GetDepartment() << endl;
	cout << Employee1.GetSalary() << endl;


	system("pause>0");
	return 0;
}
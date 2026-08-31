#include <iostream>
using namespace std;
enum Gender { Male, Female };
enum Status { Married, Single };
enum Color { Blue, Red, Green, Yellow };
int mian()
{
	Gender MyGender;
	Status MyStatus;
	Color MyColor;
	MyGender = Gender::Male;
	MyStatus = Status::Single;
	MyColor = Color::Blue;
	cout << "Name : Ali Al-emame\nAge : 19\n" "Country : Jordan\nCity : Zarqa\n";
	cout << "Color is : " << MyColor << endl;
	cout << "Gender is : " << MyGender << endl;
	cout << "Status is : " << MyColor << endl;


}
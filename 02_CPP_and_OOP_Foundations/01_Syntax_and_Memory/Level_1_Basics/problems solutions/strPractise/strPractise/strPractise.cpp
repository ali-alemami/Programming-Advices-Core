#include <iostream>
using namespace std;

enum enFavouriteColor { Red, Green, Blue, Yellow };
enum enGender { Male, female };
enum enMartialStatus { Married, Single };


struct strAddress
{
	string StreetName;
	int BuildingNumber;
	string POBox;
	string ZipCode;
};

struct strContactInfo
{
	string Phone;
	string Email;

	strAddress address;
};

struct strPerson
{
	string FullName;
	strContactInfo ContactInfo;

	enGender Gender;
	enFavouriteColor FavouriteColor;
	enMartialStatus MartialStatus;
};


int main()
{
	strPerson Person1;

	Person1.FullName = "Ali Alemame";
	Person1.ContactInfo.Phone = "0780020203";
	Person1.ContactInfo.Email = "alialemame@gmai.com";
	Person1.ContactInfo.address.BuildingNumber = 13;
	Person1.ContactInfo.address.POBox = "1234";
	Person1.ContactInfo.address.StreetName = "street street";
	Person1.ContactInfo.address.ZipCode = "1111";
	Person1.Gender = enGender::Male;
	Person1.MartialStatus = enMartialStatus::Married;
	Person1.FavouriteColor = enFavouriteColor::Blue;



	cout << Person1.ContactInfo.address.ZipCode << endl;
	return 0;
}
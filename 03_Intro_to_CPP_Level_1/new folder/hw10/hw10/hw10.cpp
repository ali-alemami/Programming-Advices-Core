#include <iostream>
using namespace std;
enum enColor{ Red,Blue,Green,Yellow };
enum enGender { Male, Female };
enum enMaritalStatus { Single, Married };

struct stAddress
{
	string StreetName;
	string BuildingNo;
	string BOPox;
	string ZipCode;
};

struct stContactInfo
{
	string Phone;
	string Email;
	stAddress address;
};


struct stPerson
{
	string FirstName;
	string LastName;
	stContactInfo ContactInfo;
	enColor FavourateColor;
	enGender Gender;
	enMaritalStatus MaritalStatus;

};
int main()
{
	stPerson Person1;
	Person1.FirstName = "Ali";
	Person1.LastName = "Al-emame";

	Person1.ContactInfo.Phone = "0780020203";
	Person1.ContactInfo.Email = "ali.alemame01@gmail.com";

	Person1.ContactInfo.address.StreetName = "StreetStreet";
	Person1.ContactInfo.address.BuildingNo = "11";
	Person1.ContactInfo.address.BOPox = "4444";
	Person1.ContactInfo.address.ZipCode = "1234";

	Person1.FavourateColor = enColor::Blue;
	Person1.Gender = enGender::Male;
	Person1.MaritalStatus = enMaritalStatus::Married;

	return 0;
}

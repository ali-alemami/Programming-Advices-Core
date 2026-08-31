#include <iostream>
#include "clsLoginScreen.h"
#include "Global.h"

using namespace std;

int main()
{
	while (!LockedSystem)
	{
		clsLoginScreen::ShowLoginScreen();
	}
	
	system("pause>0");
	return 0;
}
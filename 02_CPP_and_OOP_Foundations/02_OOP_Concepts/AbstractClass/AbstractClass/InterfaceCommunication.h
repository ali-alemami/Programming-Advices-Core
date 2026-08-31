#pragma once

#include <iostream>

using namespace std;

class InterfaceCommunication
{
public:

	virtual void SendEmail(string Head, string Body) = 0;
	virtual void SendFax(string Head, string Body) = 0;
	virtual void SendSMS(string Head, string Body) = 0;
};


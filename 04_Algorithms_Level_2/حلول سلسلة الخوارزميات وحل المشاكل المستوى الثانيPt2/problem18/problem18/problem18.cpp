#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";

	cout << "Enter the text\n";
	getline(cin, Text);

	return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < size(Text); i++)
	{
		Text[i] = char(int(Text[i] + EncryptionKey));
	}
	return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < size(Text); i++)
	{
		Text[i] = char(int(Text[i] - EncryptionKey));
	}
	return Text;
}

int main()
{
	short EncryptionKey = 2;
	string Text = ReadText();
	string TextAfterEncryption = EncryptText(Text, EncryptionKey);
	string TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

	cout << "Text before encryption : " << Text << endl;
	cout << "Text after encryption  : " << TextAfterEncryption << endl;
	cout << "Text after decryption  : " << TextAfterDecryption << endl;

	return 0;
}
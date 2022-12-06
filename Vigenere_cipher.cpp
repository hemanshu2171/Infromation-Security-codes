#include<bits/stdc++.h>
using namespace std;

string generateKey(string str, string key)
{
	int n = str.size();
	int m = key.size();

	for(int i=key.size(); i<n; i++){
		key.push_back(key[i%m]);
	}
	return key;
}

string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		char x = (str[i] + key[i]) %26;
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		char x = (cipher_text[i] - key[i] + 26) %26;
		x += 'A';
		
		orig_text.push_back(x);
	}
	return orig_text;
}

int main()
{
	
	string msg, key_text;
    
    cout<<"Enter the message: ";
    cin>>msg;
    
    cout<<"Enter the key text: ";
    cin>>key_text;

	string key = generateKey(msg, key_text);
	string cipher_text = cipherText(msg, key);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Decrypted Text : "
		<< originalText(cipher_text, key);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

string vernam(string msg, string key){
    
    transform(msg.begin(),msg.end(),msg.begin(),::toupper);
    transform(key.begin(),key.end(),key.begin(),::toupper);
    
    int n = msg.size();
    string cipher(n,'#');
    
    for(int i=0; i<n; i++){
        cipher[i] = ((msg[i]-'A')^(key[i]-'A'));

        if(cipher[i]>25)
            cipher[i] -= 26;
        cipher[i] = (char)(cipher[i]+'A');
    }

    return cipher;
}

string _decrypt(string cipher, string key){
    int n = cipher.size();
    string decrypt(n,'#');
    
    for(int i=0; i<n; i++){
        decrypt[i] = ((cipher[i]-'A')^(key[i]-'A'));

        decrypt[i] = (char)(decrypt[i]+'A');
    }
    return decrypt;
}

int main() {
	string plain_text;
    cout<<"Enter the message: \n";
	cin>>plain_text;
	
	string key;
    cout<<"\nEnter the key: \n";
	cin>>key;
	
	string encrypt = vernam(plain_text, key);
	cout<<"\nEncrypted text: \n"<<encrypt;
	
    string decrypt = _decrypt(encrypt, key);
    cout<<"\n\nDecrypted text: \n"<<decrypt;

	return 0;
}
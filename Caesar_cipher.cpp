#include<bits/stdc++.h>
using namespace std;

string encode(string s, int shift){
    for(int i=0; i<s.size(); i++){
        s[i]=(s[i]-'A'+shift)%26+'A';
    }
    return s;
}

string decode(string s, int shift){
    for(int i=0; i<s.size(); i++){
        s[i]=(s[i]-'A'-(shift%26)+26)%26+'A';
    }
    return s;
}

int32_t main()
{
    // Caesar cipher
    
    string s;
    cout<<"Enter the message: ";
    cin>> s;
    
    int shift;
    cout<<"Enter shift: ";
    cin>>shift;
    
    string encoded = encode(s,shift);
    cout<<"\nEncrypted message: \n";
    cout<<encoded<<endl;
    
    cout<<"\nDecrypted message: \n";
    string decoded = decode(encoded,shift);
    cout<<decoded<<endl;
    
}
#include<bits/stdc++.h> 
using namespace std; 

vector< vector<char> > generateTable(){ 
    vector< vector<char> > table(26,vector<char>(26)); 

    char x='A'; 

    for(int i=0;i<26;i++){ 

        char last=x; 

        for(int j=0;j<26;j++){ 
            table[i][j]=x; 

        x++; 

        if(x>'Z'){ 

        x='A'; 

        } 

    } 

    last++; 

    x=last; 

    }  

 
    cout<<"Table \n";
    for(int i=0;i<26;i++){ 
        for(int j=0;j<26;j++){ 

            cout<<table[i][j]<<" "; 

        } 
        cout<<endl;
    } 
    cout<<"\n\n"; 

    return table; 

} 

  

int main(){ 

string plainText,keyword; 

cout<<"Enter plain text\n"; 

getline(cin,plainText); 

cout<<"Enter Keyword\n"; 

getline(cin,keyword); 


//Generating key by repeating keyword 

string key=keyword; 

int i=0; 

while(1){ 

if(key.length()==plainText.length()){ 

break; 

} 

key+=(keyword[(i%(keyword.length()))]); 

i++; 

} 

 

vector< vector<char> > table= generateTable(); 

string cipherText=""; 

for(int i=0;i<plainText.length();i++){ 

if(plainText[i]==' ')continue; 

cipherText+=(table[key[i]-'A'][plainText[i]-'A']); 

} 

cout<<"Plain text ---> "<<plainText; 

cout<<"\nKey ---> "<<key; 

cout<<"\nKeyword ---> "<<keyword; 

cout<<"\nCipher Text ---> "<<cipherText; 

} 

 
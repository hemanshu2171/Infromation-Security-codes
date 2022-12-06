#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int32_t main() {
    string msg, key;
    
    cout<<"Enter the message: ";
    cin>>msg;
    
    cout<<"Enter the key: ";
    cin>>key;
    
    transform(begin(msg),end(msg),begin(msg),::toupper);
    transform(begin(key),end(key),begin(key),::toupper);
    
    unordered_set<char> s;
    map<char,char> m, d;
    
    set<char> a;
    for(int i=0; i<26; i++)
        a.insert((char)(i+'A'));
    
    int i=0;
    for(auto &e:key){
        if(s.find(e) == s.end())
            m[(char)(i+'A')]=e, s.insert(e), a.erase(e), i++;
    }
    
    while(i<26){
        m[(char)(i+'A')] = *a.begin();
        a.erase(a.begin());
        i++;
    }
    
    cout<<"\n";
    for(auto &it:m){
        cout<<it.first<<" ";
        d[it.second] = it.first;
    }
    cout<<endl;
    
    for(auto &it:m)
        cout<<it.second<<" ";
    cout<<"\n\n";

    cout<<"Encrypted message: ";
    string encrypt;

    for(auto &e:msg)
        encrypt.push_back(m[e]);

    cout<<encrypt<<endl;
    
    cout<<"Decrypted message: ";
    
    for(auto &e:encrypt)
        cout<<d[e];

	return 0;
}

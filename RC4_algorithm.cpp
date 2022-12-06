#include <bits/stdc++.h>
using namespace std;

int main() {
    int plain_text[4];
    cout<<"Enter the plain text:\n";
    for(int i=0; i<4; i++)
        cin>>plain_text[i];
    
	int key[4];
	cout<<"Enter the key:\n";
	for(int i=0; i<4; i++)
	    cin>>key[i];
	    
	int T[8];
	for(int i=0; i<8; i++)
	    T[i]=(key[i%(4)]);
	
	cout<<"Temporary vector :\n";
	for(int i=0; i<8; i++)
	    cout<<T[i]<<" ";
	cout<<"\n\n";
	    
	int S[8];
	for(int i=0; i<8; i++)
	    S[i]=i;    
	    
	cout<<"Initial value of S :\n";
	for(int i=0; i<8; i++)
	    cout<<S[i]<<" ";
	cout<<"\n\n";
	    
	int i=0, j=0;
	cout<<"Value of S after \n";
	for(i=0; i<8; i++){
	    j=(j+S[i]+T[i])%8;
	    swap(S[i],S[j]);
	    
	    cout<<"Iteration "<<i+1<<":\n";
    	for(int i=0; i<8; i++)
    	    cout<<S[i]<<" ";
    	cout<<"\n\n";
	}
	
	int n=0;
	i=0, j=0;
	
	while(n<4){
	    i+=1;
	    j=(j+S[i])%8;
	    
	    swap(S[i],S[j]);
	    int t = (S[i]+S[j])%8;
	    
	    key[n]=S[t];
	    
	    n++;
	}
	
	cout<<"Updated key :\n";
	for(int i=0; i<4; i++)
	    cout<<key[i]<<" ";
	cout<<"\n\n";
	
	int encrypt[4];
	for(i=0; i<4; i++)
	    encrypt[i] = plain_text[i] ^ key[i];
	    
	cout<<"The encrypted text is ";
	for(i=0; i<4; i++)
	    cout<<encrypt[i]<<" ";
	
	return 0;
}

//1 2 2 2
//1 2 3 6



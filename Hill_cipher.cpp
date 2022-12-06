#include <bits/stdc++.h>
using namespace std;

string solve(vector<vector<int>> &k_mat, vector<vector<int>> &m_mat, string msg, int n){
	int m=msg.size();
	
	int i,j,k;
	int idx=0;
	
	for(i=0; i<n; i++){
		for(j=0; j<1; j++)
			m_mat[i][j] = (msg[idx++]-'A');
	}
	
	string res;
	for(i=0; i<n; i++){
		int sum=0;
		for(j=0; j<1; j++){
			for(k=0; k<n; k++)
				sum+=k_mat[i][k]*m_mat[k][j];
		}
		res+=((char)(sum%26+'A')); 
	}
	return res;
}

int main() {
    string key, msg;
    cout<<"Key 	   ---> ";
    cin>>key;
    
    cout<<"Messages --> ";
    cin>>msg;
    
    int n=sqrt(key.size());
    int m=msg.size();
	
	vector<vector<int>> k_mat(n,vector<int>(n));
	vector<vector<int>> m_mat(n,vector<int>(1));
	
	int k=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			k_mat[i][j]=(key[k++]-'A');
	}
	
	cout<<"\nEncrypted message: \n";
    for(int i=0; i<=m-n; i+=n){
    	cout<<solve(k_mat,m_mat,msg.substr(i,n),n);
	}
    
    return 0;
}

//VIEW
//MEETBX

//CIPHERING
//SAFEMESSAGES


#include <bits/stdc++.h>
using namespace std;

pair<int,int> get_idx(vector<vector<char>> &mat, char c){
    if(c=='j')
        c='i';
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            if(c==mat[i][j])
                return {i,j};
    }
    return {-1,-1};
}

void encode(string msg, vector<vector<char>> &mat){
    
    for(int i=0; i<msg.size()-1; i++){
        if(msg[i]==msg[i+1])
            msg.insert(msg.begin()+i,'x'), i++;
    }
    
    if(msg.size()&1)
        msg.push_back('z');
    
    for(int i=0; i<msg.size(); i+=2){
        auto x = get_idx(mat,msg[i]);
        auto y = get_idx(mat,msg[i+1]);
        
        int x_r = x.first, x_c = x.second;
        int y_r = y.first, y_c = y.second;
        
        if(x_r == y_r)
            cout<<mat[x_r][(x_c+1)%5]<<mat[y_r][(y_c+1)%5];
        else if(x_c == y_c)
            cout<<mat[(x_r+1)%5][x_c]<<mat[(y_r+1)%5][y_c];
        else
            cout<<mat[x_r][y_c]<<mat[y_r][x_c];
        cout<<endl;
    }
}

int32_t main() {
    string msg, key;
    cout<<"Enter the message: ";
    cin>>msg;
    
    cout<<"Enter the key:     ";
    cin>>key;
    
    vector<vector<char>> mat(5,vector<char>(5,'#'));
    int i=0, j=0;
    
    set<char> s, a;

    for(char c='a'; c<='z'; c++)
        if(c!='j')
            s.insert(c);
    
    for(auto &e:key){
        if(a.find(e) == a.end()){
            mat[i][j++]=e;
            a.insert(e);
            s.erase(e);
        }
        if(j==5)
            i++, j=0;
    }
    
    while(i<5){
        mat[i][j++]=*s.begin();
        s.erase(s.begin());
        if(j==5)
            i++, j=0;
    }
    
    for(auto &v:mat){
        for(auto &e:v)
            cout<<e<<" ";
        cout<<endl;
    }
    
    cout<<"Encrypted message:\n";
    encode(msg,mat);
}



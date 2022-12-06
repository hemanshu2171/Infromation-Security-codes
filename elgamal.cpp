#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int power(int a,unsigned int b,int mod){
    int res = 1;
    int y = a;
 
    while (b > 0){
        if (b % 2 != 0)
            res = (res * y) % mod;
        y = (y * y) % mod;
        b = b / 2;
    }
 
    return res % mod;
}

void find_prime_factors(unordered_set<int> &s, int n)
{
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }

    if (n > 2)
        s.insert(n);
}

int find_primitive(int n)
{
    unordered_set<int> s;
    int phi = n-1;
    find_prime_factors(s, phi);
 
    // Check for every number from 2 to phi
    for (int r=2; r<=phi; r++)
    {
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (power(r, phi/(*it), n) == 1)
            {
                flag = true;
                break;
            }
         }
         if (flag == false)
           return r;
    }
    return -1;
}


int mod_inverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}

int gcd(int a,int b){
    if(a < b)
        return gcd(b, a);
    else if( a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int coPrime(int q){
	
	for(int i=2;i<q;i++){
		if(gcd(i,q)==1) return i;
	}
	return -1;
}


int main(){
	
	int p;  // prime no.
	cout<<"Enter prime no. = ";
	cin>>p;
	
	int e1; // primitive root
	e1 = find_primitive(p);
	cout<<"Primitive root of P = e1 = "<<e1<<"\n";
	
	int d; // private key
	cout<<"Enter random no. d (private key) : ";
	cin>>d;
	
	int yA = power(e1,d,p);
	cout<<"Public key corresponding to private key d = y1 = "<<yA<<"\n";
	
	int plain_text;
	int m; // = HashCode(plain_text);
	cout<<"\nEnter hashed message m = ";
	cin>>m;
	
	int k; // gcd(k,p-1)=1
	k = coPrime(p-1);
    cout<<"Co-prime of "<<m<<":\n";
	cout<<k<<"\n";
	
	int s1,s2;
	
	s1 = power(e1,k,p);
	
	int inverse_K = mod_inverse(k,p-1);
	cout<<"\nInverse k ="<<inverse_K<<"\n";
	
	s2 = (inverse_K*(m-d*s1))%(p-1);
	if(s2<0) s2 = s2 + (p-1);
	
	cout<<"\ns1 and s2 = "<<s1<<" "<<s2<<"\n";
	
	// find v1 and v2
	int v1,v2;
	
	v1 = power(e1,m,p);
	v2 = (power(yA,s1,p)*power(s1,s2,p))%p;
	cout<<"\nv1 and v2 = "<<v1<<" "<<v2<<"\n";
}

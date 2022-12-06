#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define int long long int

int power(int x, int y, int p){
	
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int32_t main() {
    int q;
	cout<<"Enter a prime no q: ";
	cin>>q;
	
	// find the primitive root
	int a=-1;
	for(int i=2; i<q; i++){
	    unordered_set<int> s;
	    for(int j=1; j<q; j++)
	        s.insert(power(i,j,q));
	    if(s.size() == q-1){
	        a=i;
	        break;
	    }
	}
	cout<<"\nPrimitive root: \n";
	cout<<a<<"\n\n";
	int x_a, x_b;
	
	cout<<"Enter the private keys\nx_a: ";
	cin>>x_a;
	
	cout<<"x_b: ";
	cin>>x_b;
	
	int y_a, y_b;
	y_a = power(a,x_a,q);
	y_b = power(a,x_b,q);
	
	int k1, k2;
	k1 = power(y_b,x_a,q);
	k2 = power(y_a,x_b,q);
	
	cout<<"\nKey 1: "<<k1<<endl;
	cout<<"Key 2: "<<k2;
	
	return 0;
}

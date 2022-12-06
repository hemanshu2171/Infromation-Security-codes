#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n);
int generate_encryption_key(int phi);
int generate_decryption_key(int e, int phi);
int encrypt(int message, int e, int n);
int decrypt(int cipher, int d, int n);
int gcd(int a, int b);
int power(int x, int y, int p);

int main()
{
    int message{};
    std::cout << "Enter the message text: ";
    std::cin >> message;

    int p{};
    do {
        std::cout << "Enter a prime number (p): ";
        std::cin >> p; 
    } while (!isPrime(p));

    int q{};
    do {
        std::cout << "Enter another prime number (q): ";
        std::cin >> q; 
    }  while(!isPrime(q));

    int n{ p * q };
    std::cout << "\nn = p * q = " << n << '\n';
    
    int phi{ (p - 1) * (q - 1) };
    std::cout << "\nphi = (p - 1) * (q - 1) = " << phi << '\n';

    int e{ generate_encryption_key(phi) };
    std::cout << "\nEncryption Key: { " << e << ", " << n << " }\n";

    int d{ generate_decryption_key(e, phi) };
    std::cout << "\nDecryption Key: { " << d << ", " << n << " }\n";

    int cipher{ encrypt(message, e, n) };
    std::cout << "\nCipher Text: " << cipher << '\n';

    int text{ decrypt(cipher, d, n) };
    std::cout << "\nPlain Text: " << text << '\n';

    return 0;
}

int power(int x, int y, int p){
    int res = 1;
    
    x=x%p;
    
    if(x==0)
        return 0;
    
    while(y){
        if(y&1)
            res=(res*x)%p;
            
        x=(x*x)%p;
        y=y>>1;
    }
    return res;
}

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

bool isPrime(int n)
{
    for (int i{ 2 }; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


int generate_encryption_key(int phi)
{
    for (int e{2}; e < phi; ++e)
    {
        if (gcd(e, phi) == 1)
            return e;
    }

    return -1;
}

int generate_decryption_key(int e, int phi)
{
    int d{ static_cast<int>(phi / e) };

    while ((d * e) % phi != 1)
        ++d;

    return d;
}

int encrypt(int message, int e, int n)
{
    return power(message,e,n);
}

int decrypt(int cipher, int d, int n)
{    
    return power(cipher,d,n);
}
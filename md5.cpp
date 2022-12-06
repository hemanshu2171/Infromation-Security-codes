#include<bits/stdc++.h>
#include "valarray"
using namespace std;
typedef long long ll;

struct Buffer {
	ll A, B, C, D;
};

string add_string(string s, int len)// function to add substring to string
{
	string output = "";
	
	for(int i=0; i<len; i++)
		output += s;
	return output;	
}

//encryption function 
struct Buffer encrypt(ll A, ll B, ll C, ll D, ll func, string msg_block, valarray<ll> keys)
{
	Buffer buffer;
	ll func_value;
	ll output=0;
	for(int i=0; i<16; i++)// for each function it runs 16 times
	{
		if(func == 1)
			func_value = (B & C) | (~B & ~D);
		if(func == 2)
			func_value = (B & D) | (C & ~D);	
		if(func == 3)
			func_value = (B^C)^D;
		if(func == 4)	
			func_value = C^(B|(~D));
		
		output += func_value + A;// adding function value to A
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += stoll(msg_block.substr(i*32, 32), 0, 2);// adding message blocks
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += keys[i];// adding key block
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output = ((output << 3)|(output >> (32 - 3)))&(ll(pow(2,32)) - 1); // left rotate S bits, S = 3
		
		output += B;// adding B
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		//rearranging
		A = D;
		D = C;
		C = B;
		B = output;		
	}
	buffer.A = A;
	buffer.B = B;
	buffer.C = C;
	buffer.D = D;
	return buffer;
}

//generating 64 keys
valarray<ll> calcKs()
{
    double s, pwr;
    int i;
    valarray<ll> k(64);

    pwr = pow( 2, 32);
    for (i=0; i<64; i++) {
        s = fabs(sin(1+i));
        k[i] = (ll)( s * pwr );
    }
    return k;
}

int main()
{
	//binary_msg is the final input in binary form to the encryption algorithm
	string msg, binary_msg;
	ll blocks = 0;
	
	cout<<"Enter the message "<<endl;
	cin>>msg;
	
	valarray<ll> keys = calcKs();
	blocks += floor((msg.length()*8)/512);
	ll remain_len = msg.length()*8 - floor((msg.length()*8)/512)*512;
	
	for(int i=0; i<msg.length(); i++)
		binary_msg +=  bitset<8> (int(msg[i])).to_string();
	
	if(remain_len <= 447)
	{
		blocks++;
		binary_msg += "1";
		binary_msg += add_string("0", 447-remain_len);
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	else
	{
		blocks+=2;
		binary_msg += "1";
		binary_msg += add_string("0", 511-remain_len);
		binary_msg += bitset<448> (0).to_string();
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	
	//buffer initialization
	ll A = 0x67425301;
	ll B = 0xEDFCBA45;
    ll C = 0x98CBADFE;
    ll D = 0x13DCE476;
	Buffer x ;
	
	
	for(int i=1; i<=blocks; i++)
	{
		string msg_block = binary_msg.substr((i-1)*512, 512);
		
		x = encrypt(A, B, C, D, 1, msg_block, keys[slice(0, 16, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 2, msg_block, keys[slice(15, 32, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 3, msg_block, keys[slice(31, 48, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 4, msg_block, keys[slice(47, 64, 1)]);
	}	
	
	cout<<"Hashed Value: ";
	cout<<hex<<x.A;
	cout<<hex<<x.B;
	cout<<hex<<x.C;
	cout<<hex<<x.D;
	
}

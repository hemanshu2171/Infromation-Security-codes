/*
*
* @Author : Lakshay (11912077)
*
*/
#include<bits/stdc++.h>
#include "valarray"
using namespace std;
typedef long long ll;

struct Buffer {
	ll A, B, C, D, E;
};

vector<string> msg_chunk_array;

string add_string(string s, int len)// function to add substring to string
{
	string output = "";
	
	for(int i=0; i<len; i++)
		output += s;
	return output;	
}

//encryption function 
struct Buffer encrypt(Buffer x, ll func, string msg_block, ll key)
{
	Buffer buffer;
	ll func_value;
	ll output=0;
	ll A = x.A;
	ll B = x.B;
	ll C = x.C;
	ll D = x.D;
	ll E = x.E;
	
	
	for(int i=0; i<20; i++)// for each function it runs 20 times
	{
		if(func == 1)
			func_value = (B | C) & (~B | D);
		if(func == 2 || func == 4)
			func_value = B^(C^D);	
		if(func == 3)
			func_value = (C) & (B | D) & (C | D);
		
		output += func_value + E; // adding function value
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		E = D;
		D = C;
		C = ((B << 30)|(B >> (2)))&(ll(pow(2,32)) - 1);
		B = A;
		A = ((A << 5)|(A >> (27)))&(ll(pow(2,32)) - 1);
		
		output += A;// adding A
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += stoll(msg_chunk_array[(func - 1)*16 + i], 0, 2);	//adding message bits
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += key; // adding key
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		A = output;	
	}
	x.A = A;
	x.B = B;
	x.C = C;
	x.D = D;
	x.E = E;
	return x;
}


int main()
{
	//binary_msg is the final input in binary form to the encryption algorithm
	string msg, binary_msg;
	ll blocks = 0;
	
	cout<<"Enter the message "<<endl;
	cin>>msg;
	
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
    ll E = 0xC3D2E1F0;
        
	Buffer x ;
	x.A = A;
	x.B = B;
	x.C = C;
	x.D = D;
	x.E = E;
	


	for(int i=1; i<=blocks; i++)
	{
		string msg_block = binary_msg.substr((i-1)*512, 512);
		msg_chunk_array.clear();
		
		//16 32 bit message words from 512 bit block
		for(int i=0; i<80; i++)
		{
			if(i<16)
				msg_chunk_array.push_back(msg_block.substr((i)*32, 32));
			else
				msg_chunk_array.push_back((bitset<32> (string(msg_chunk_array[i-16])) ^ bitset<32> (string(msg_chunk_array[i-14])) 
				^ bitset<32> (string(msg_chunk_array[i-8])) ^ bitset<32> (string(msg_chunk_array[i-3]))).to_string());	
		}
		
		x = encrypt(x, 1, msg_block, 0x5A827999);// 0  <= i <= 19
		x = encrypt(x, 2, msg_block, 0x6ED9EBA1);// 20 <= i <= 39
		x = encrypt(x, 3, msg_block, 0x8F1BBCDC);// 40 <= i <= 59
		x = encrypt(x, 4, msg_block, 0xCA62C16D);// 60 <= i <= 79
	}	
	
	x.A ^= A;
	x.B ^= B;
	x.C ^= C;
	x.D ^= D;
	x.E ^= E;
	
	cout<<"Hashed Value: ";
	cout<<hex<<x.A;
	cout<<hex<<x.B;
	cout<<hex<<x.C;
	cout<<hex<<x.D;
	cout<<hex<<x.E;
	
}

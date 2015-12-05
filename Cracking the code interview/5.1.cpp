#include <bitset>
#include <iostream>
using namespace std;

int main() {
	bitset<10> N(string("1000111100"));
	bitset<10> M(string("0000010101"));
	int i = 2,j = 6;
	bitset<10> maskBit(string("1111000011"));
	string mask;
	for(int k = j;k<10;k++)
		mask.push_back('1');
	for(int k = i;k<j;k++)
		mask.push_back('0');
	for(int k = 0;k<i;k++)
		mask.push_back('1');
	
	cout<<mask<<endl;
	
	M = M<<i;
	N &= maskBit;
	N |= M;
	cout<<N<<endl;
	// cout<<M<<endl;
	// your code goes here
	return 0;
}

// public static int updateBits(int n, int m, int i, int j) { 

// int max = ~0; /* All 1’s */

// // 1’s through position j, then 0’s
// int left = max - ((1 << j) - 1);
// // 1’s after position i
// int right = ((1 << i) - 1);
// // 1’s, with 0s between i and j
// int mask = left | right;
// // Clear i through j, then put m in there

// return (n & mask) | (m << i);

// }
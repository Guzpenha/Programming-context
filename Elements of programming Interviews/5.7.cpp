#include <iostream>
#include <algorithm>
#define REPP(A,B,C) for(int A=B;A<C;A++)
#define DRS(X) string X; cin>>X;
using namespace std;


// No negative allowerd. No digit>10 conversion allowerd.
// string convertBase(int b1,string s,int b2){
// 	string ans;
// 	int totalValue =0;
// 	REP(i,s.size()){
// 		totalValue*=b1;
// 		totalValue+= s[i]-'0';		
// 	}
// 	int num;
// 	while(totalValue){
// 		num = totalValue % b2;
// 		ans.push_back('0'+num);
// 		totalValue/=b2;
// 	}
// 	if(!ans.size())
// 		ans.push_back('0');
// 	reverse(ans.begin(),ans.end());
// 	return ans;
// }

// Negative and >10 allowed
string convertBase(int b1,string s,int b2){
	string ans;
	int totalValue =0;
	REPP(i,((s[0] == '-')? 1 : 0),s.size()){
		totalValue*=b1;
		totalValue+=  ( isdigit(s[i])? s[i]-'0' : s[i]-'A' + 10);		
	}
	int num;
	while(totalValue){
		num = totalValue % b2;
		ans.push_back( (num<10? '0'+num : 'A'+ num - 10));
		totalValue/=b2;
	}
	if(!ans.size())
		ans.push_back('0');
	if(s[0]=='-')
		ans.push_back('-');
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	DRS(input);
	cout<<convertBase(10,input,16)<<endl;
	return 0;
}
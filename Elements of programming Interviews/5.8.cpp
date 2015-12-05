#include <iostream>
#define REP(A,B) for(int A=0;A<B;A++)

using namespace std;

// A conversion from base 27 to decimal base.

int ssDecodeColID(string col){
	int ans=0;
	REP(i,col.size()){
		ans*= 26;
		ans+= col[i] -'A' + 1;		
	}
	return ans;
}

int main(){
	string col;
	cin>>col;
	cout<<ssDecodeColID(col)<<endl;
	return 0;
}


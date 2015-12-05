#include <iostream>


//STRING MUL DONE WRONG, integers will overflow

#define IREP(A,B) for(int A=B-1; A>=0 ;A--)
#define SZ(X) (int)X.size()

using namespace std;

int stringMul(string s1, string s2){
	if(s1=="0" || s2 == "0")
		return 0;
	int ans,i_count,j_count;
	i_count=j_count=1;
	ans=0;
	IREP(i,SZ(s1)){
		j_count=1;
		IREP(j,SZ(s2)){			
			ans+= (s1[i] - '0') *(s2[j] -'0') * i_count * j_count;			
			j_count*=10;
		}
		i_count*=10;
	}

	return ans;
}


int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<stringMul(s1,s2)<<endl;
	return 0;
}
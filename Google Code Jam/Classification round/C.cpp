#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

#define PVI(X) for(int x=0;x<X.size();x++){printf("%d ",X[x]);}printf("\n");
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define CASENZ int ___T, case_n = 1; scanf("%d ", &___T); while (___T != 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

int mul_matrix[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

int input_to_v(char i){
	if(i == 'i')
		return 2;
	else if(i == 'j')
		return 3;
	else if(i == 'k')
		return 4;
	return -1;
}

int mul_q(int v1,int v2){
	int res =0;
	bool neg = (v1<0);
	if(!neg){
		res = mul_matrix[v1-1][v2-1];
	}else{
		res = -(mul_matrix[(-v1)-1][v2-1]);
	}
	return res;
}

int main(){	
	CASET{
		int ans;
		ans=0;
		DRII(L,X);
		string word,finalstring;
		finalstring="";
		cin>>word;
		// int mul_part =1;
		// if(X>1){
		// 	REP(i,word.size()){
		// 		mul_part=mul_q(mul_part,input_to_v(word[i]));
		// 	}
		// }
		REP(i,X){
			finalstring+=word;
		}		
		int acc = 1;
		int cnt=0;
		vector<int> found_i;		
		while(cnt!=finalstring.size()){
			int v1=input_to_v(finalstring[cnt]);
			acc = mul_q(acc,v1);
			cout<<acc<<" ";
			if(acc==2){
				found_i.PB(cnt);
				break;
			}
			cnt++;
		}
		PVI(found_i);
		//PVI(found_i);
		bool found_k =false;
		REP(i,found_i.size()){
			acc=1;
			vector<int> found_j;
			REPP(j,(found_i[i]+1),finalstring.size()){				
				int v1=input_to_v(finalstring[j]);
				//cout<<finalstring[j]<<" ";
				acc = mul_q(acc,v1);
				if(acc==3)
					found_j.PB(j+i);
			}			
			//cout<<endl;
			int acc2;
			found_k = false;
			//PVI(found_j);
			REP(j,found_j.size()){
				acc2=1;
				REPP(k,(found_j[j]+1),finalstring.size()){					
					int v1=input_to_v(finalstring[k]);
					//cout<<finalstring[k]<<" ";
					acc2 = mul_q(acc2,v1);
					if(acc2==4){
						if(k==(finalstring.size()-1)){
							found_k=true;
							break;
						}
					}
				}
				//cout<<endl;
				if(found_k)
					break;
			}			
			if(found_k)
				break;
		}
		if(found_k)
			printf("Case #%d: YES\n",case_n++);
		else
			printf("Case #%d: NO\n",case_n++);		
	}
	return 0;
}

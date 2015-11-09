#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define PVI(X) for(int x=0;x<X.size();x++){printf("%d ",X[x]);}printf("\n");
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define RIIII(X, Y, Z, K) scanf("%d%d%d%d", &X, &Y, &Z, &K)
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRIIII(X, Y, Z, K) int X, Y, Z, K; scanf("%d%d%d%d", &X, &Y, &Z, &K)
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


int main(){	
	int n,t;
	while(cin>>n){
		vector<int> T;
		REP(i,n){
			RI(t);
			t+=11;
			T.PB(t);
		}
		sort(T.begin(),T.end(), std::greater<int>());
		// PVI(T);
		int ans1 =0;				
		ans1+= min(abs(T[0]-T[SZ(T)-1]), abs(24-abs(T[0]-T[SZ(T)-1])));						
		REPP(i,1,(SZ(T))-2){	
			ans1+=(T[i]-T[i+1]);			
			i++;	
		}		

		int ans2=0;
		REP(i,(SZ(T))-1){	
			ans2+=(T[i]-T[i+1]);			
			i++;	
		}	
		cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}

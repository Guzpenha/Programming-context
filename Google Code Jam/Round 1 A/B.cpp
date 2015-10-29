#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>


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
bool all_reached_zeros(unordered_map<int,bool> z){
	for(unordered_map<int,bool>::iterator it = z.begin();it!=z.end();it++){
		if(!it->second)
			return false;
	}
	return true;
}

int main(){	
	CASET{
		int ans=0;
		DRII(B,N);
		vector<int> barbers;
		unordered_map <int,bool> zeros;
		REP(i,B){
			DRI(timing);
			barbers.PB(timing);
			zeros[i]=false;
		}
		vector<int> pattern;
		vector<int> cur_b(B,0);
		REP(i,B){
			// pattern.PB(i+1);
			cur_b[i]=barbers[i];
		}
		// PVI(pattern);
		while(!all_reached_zeros(zeros)){
			int min = *std::min_element(cur_b.begin(), cur_b.end());
			REP(i,B){
				cur_b[i]-=min;
			}
			REP(i,B){
				if(cur_b[i]==0){
					cur_b[i]=barbers[i];
					zeros[i]=true;
					pattern.PB(i+1);
					if(all_reached_zeros(zeros))
						break;
				}
			}
		}
		// PVI(pattern);
		// if(pattern.size()>B)
			// pattern.erase(pattern.begin()+B);
		// cout<<N/pattern.size()<<endl;
		if(N <= B){
			printf("Case #%d: %d\n",case_n++,N);
		}else{
			// N=N-B;
			if(N%pattern.size()==0){
				printf("Case #%d: %d\n",case_n++,pattern[pattern.size()-1]);
			}
			else{
				printf("Case #%d: %d\n",case_n++,pattern[(N%pattern.size())-1]);
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

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


int main(){	
	CASET{
		int ans,D;
		map<int,int> plates;
		ans=0;
		RI(D);
		REP(i,D){
			DRI(P);
			if(plates.find(P)==plates.end()){
				plates[P]=1;
			}else{
				plates[P]++;
			}
		}
		int m,p_m,best_ans;
		best_ans=plates.rbegin()->first;
		while(true){
			//for(std::map<int,int>::iterator it=plates.begin(); it!=plates.end(); ++it)
			//	cout<<it->first<<"=>"<<it->second<<endl;
			m = plates.rbegin()->first;
			p_m = plates.rbegin()->second;
			if( (((m/2)+(m%2))+p_m) < m){
				map<int,int> new_plates = plates;			
				new_plates.erase((--new_plates.end()));			
				ans+=p_m;
				if(m%2==0){
					if(new_plates.find((m/2))==new_plates.end())
						new_plates[(m/2)] = (2 * p_m);
					else
						new_plates[(m/2)] = new_plates[(m/2)] +  (2 * p_m);						
				}else{
					if(new_plates.find(((m/2)+1))==new_plates.end())
						new_plates[((m/2)+1)] = (p_m);
					else 
						new_plates[((m/2)+1)] = new_plates[((m/2)+1)] +(p_m);
					if(new_plates.find((m/2))==new_plates.end())
						new_plates[(m/2)] = (p_m);
					else
						new_plates[(m/2)] = new_plates[(m/2)] +(p_m);
				}
				best_ans = min(ans+new_plates.rbegin()->first, best_ans);
				plates= new_plates;
			}else{
				break;
			}
		}
		printf("Case #%d: %d\n",case_n++,best_ans);
	}
	return 0;
}

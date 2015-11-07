#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

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
	CASET{
		int matrix[9][9];
		int in;
		REP(i,9){
			REP(j,9){
				RI(in);
				matrix[i][j]= in;				
			}			
		}		

		int count[9];
		bool ans = true;

		//Lines
		REP(i,9){
			MS0(count);
			REP(j,9){
				count[matrix[i][j]-1]++;
			}
			REP(j,9){
				if(count[j]!=1)
					ans=false;				
			}
		}
		
		//Columns
		REP(i,9){
			MS0(count);
			REP(j,9){
				count[matrix[j][i]-1]++;
			}
			REP(j,9){
				if(count[j]!=1)
					ans=false;				
			}
		}

		//3x3 boxes
		int comb[3] = {0,3,6};
		REP(i,3){
			REP(j,3){
				MS0(count);
				REPP(k,comb[i],comb[i]+3){
					REPP(l,comb[j],comb[j]+3){
						count[matrix[k][l]-1]++;
					}
				}

				REP(k,9){
					if(count[k]!=1)
						ans=false;				
				}		
			}
		}



		if(ans){
			cout<<"Instancia "<<case_n++<<endl;
			cout<<"SIM"<<endl<<endl;
		}else{
			cout<<"Instancia "<<case_n++<<endl;
			cout<<"NAO"<<endl<<endl;
		}
			
	}
	return 0;
}

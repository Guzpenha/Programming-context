// RUNTIME ERROR

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
// #include "../prettyprint.hpp"

#define PVI(X) for(int x=0;x<X.size();x++){printf("%d ",X[x]);}printf("\n");
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPM(I, N) for(auto I = (N.begin()); I != N.end();I++)
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

bool isThereCycle(vector< list<int> > graph, int start){
	bool ans = false;
	stack<int> fronteira;
	vector<bool> visited(SZ(graph),false);
	fronteira.push(start);
	visited[start] = true;
	int popped;
	while(!fronteira.empty()){
		popped = fronteira.top();
		fronteira.pop();
		REPM(it,graph[popped]){
			if(visited[*it]){
				return true;
			}else{
				fronteira.push(*it);
				visited[*it] = true;
			}
		}
	}
	return ans;
}

int main(){
	DRII(k,w);
	while( k!=0 || w !=0){
		int f,t,s;	
		if(k == 3 || w == 0){
			cout<<"Y"<<endl;		
			REP(i,w)
				RII(f,t);				
		}else{
			vector< list<int> > wishGraph(k);	
			REP(i,w){
				RII(f,t);
				wishGraph[f-1].push_back(t-1);
				s = f-1;
			}		
			// cout<<wishGraph<<endl;
			cout<< (isThereCycle(wishGraph,s)? 'N':'Y' )<<endl;
		}
		RII(k,w);
	}
	return 0;
}

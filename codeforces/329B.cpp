
//Unfinished

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <list>
#include <queue>

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
#define RS(X) scanf("%c", (X))
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

struct comp{
 	bool operator()(const pair<int,int>& s1, const pair<int,int>& s2){
		return s1.S>s2.S;
  }
};


vector<int> dijkstra(int from, vector< list< unsigned int > > graph ){
	vector<int> paths(SZ(graph),1001);
	queue< pair<int,int> > fronteira;
	pair<int,int> popped;
	vector<bool> addedToFrontier(SZ(graph),false);
	fronteira.push(MP(from,0));
	// make_heap(fronteira.begin(),fronteira.end(),comp());

	while(!fronteira.empty()){
		popped = fronteira.front();
		// pop_heap(fronteira.begin(),fronteira.end()); 
		fronteira.pop();
		paths[popped.F] = popped.S;		
		REPM(it,graph[popped.F]){						
			int i= (*it);
			if(!addedToFrontier[i] && (paths[popped.F]+1) < paths[i]){
				fronteira.push(MP(i,(popped.S+1)));	
				// push_heap(fronteira.begin(),fronteira.end(),comp());									
				addedToFrontier[i] = true;
			}			
		}
	}
	return paths;
}


int main(){	
	DRII(r,c);
	char matrix[r][c];
	REP(i,r){
		REP(j,c){
			char cell;
			scanf(" %c",&cell);
			matrix[i][j] = cell;			
		}
	}	

	//map to graph
	int pos = 0;
	vector<pair<int,int> >  breeders;
	int initialPos = 0, exitPos =0;
	vector< list< unsigned int > > graph((r*c));
	REP(i,r){
		REP(j,c){	
			if(matrix[i][j]!='T'){
				if(matrix[i][j]=='S'){
					initialPos= pos;
				}else if(matrix[i][j]=='E'){
					exitPos =pos;
				}else if((matrix[i][j]-'0')>0){
					breeders.PB(MP(pos,(matrix[i][j]-'0')));
				}
				// to the right
				if(j+1<c){
					if(matrix[i][j+1]!='T'){
						graph[pos].PB(pos+1);
						graph[pos+1].PB(pos);
					}				
				}			
				//left
				if(j-1>=0){
					if(matrix[i][j-1]!='T'){
						graph[pos].PB(pos-1);
						graph[pos-1].PB(pos);
					}
				}
				//down
				if(i+1<r){
					if(matrix[i+1][j]!='T'){						
						graph[pos].PB(pos+(c));
						graph[pos+(c)].PB(pos);	
					}
				}
				if(i-1>=0){
					if(matrix[i-1][j]!='T'){
						graph[pos].PB(pos-c);
						graph[pos-c].PB(pos);	
					}
				}
			}
			pos++;			
		}
	}
	int ans=0;
	vector<int> paths = dijkstra(exitPos,graph);
	int distanceAsh =  paths[initialPos];
	REP(i,breeders.size()){
	 int distanceBreeder = paths[breeders[i].F];
	 if(distanceAsh>=distanceBreeder)
	 		ans+= breeders[i].S;
	}
	cout<<ans<<endl;
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>

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


vector<int> dijkstra(int exitPos, vector< vector< int > > graph ){
	vector<int> pathsLength;

	// pair<int,int> popped;
	// vector< pair<int,int> > fronteira;
	// vector<int> dist(V,MAXINT/2);
	// dist[from]=0;
	// fronteira.PB(MP(0,from));
	// make_heap(fronteira.begin(),fronteira.end(),Comp());

	// while(fronteira.size()!=0){
	// 	popped = fronteira.front();
	// 	pop_heap (fronteira.begin(),fronteira.end()); fronteira.pop_back();
	// 	REP(i,V){
	// 		if(graph[popped.S][i]>-1){
	// 			if(dist[i]>dist[popped.S]+graph[popped.S][i]){
	// 				dist[i]=dist[popped.S]+graph[popped.S][i];
	// 				fronteira.PB(MP(dist[i],i));
	// 				push_heap(fronteira.begin(),fronteira.end(),Comp());
	// 			}
	// 		}
	// 	}
	// }
	// return dist[to];

	return pathsLength;
}


int main(){	
	DRII(r,c);
	char matrix[r][c];
	REP(i,r){
		REP(j,c){
			char cell;
			cin>>cell;
			matrix[r][c] = cell;			
		}
	}

	//map to graph
	int pos = 0;
	unordered_map<int,int> breeders;
	int initialPos = 0, exitPos =0;
	vector< vector< int > > graph((r*c),vector< int >((r*c),0));
	REP(i,r){
		REP(j,c){	
			if(matrix[i][j]!='T'){
				if(stoi(matrix[i][j])>0){
					breeders[pos]= stoi(matrix[i][j]);
				}else if(matrix[i][j]=='S'){
					initialPos= pos;
				}else if(matrix[i][j]=='E'){
					exitPos =pos;
				}
				//to the right
				if(i+1<r){
					if(matrix[i+1][j]!='T'){
						graph[pos][pos+1] = 1;
						graph[pos+1][pos] = 1;
					}				
				}			
				//left
				if(i-1>=0){
					if(matrix[i-1][j]!='T'){
						graph[pos][pos-1] = 1;
						graph[pos-1][pos] = 1;
					}
				}
				//up
				if(j+1<c){
					if(matrix[i][j+1]!='T'){
						graph[pos][pos+(i*r)] = 1;
						graph[pos+(i*r)][pos] = 1;	
					}
				}
				if(j-1>=0){
					if(matrix[i][j-]!='T'){
						graph[pos][pos-(i*r)] = 1;
						graph[pos-(i*r)][pos] = 1;	
					}
				}
				pos++;			
			}
		}
	}

		
	vector<int> paths = dijkstra(exitPos,graph);

	int ans =0;
	REPM(it,breeders){
		if(paths[(*it).F] <= path[initialPos]){
			ans+=(*it).S;
		}
	}
	cout<<ans<<endl;
	return 0;
}

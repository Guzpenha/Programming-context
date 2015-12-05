#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <memory>

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

template <typename T>

class ListNode{
	public:
		T data;
		shared_ptr<ListNode<T>> next;
};	


shared_ptr<ListNode<int>> mergeSortedLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2 ){
	if(!l1 && !l2)
		return nullptr;
	if(!l2)
		return l1;
	if(!l1)
		return l2;

	shared_ptr<ListNode<int>> mergedHead(new ListNode<int>);
	auto tail = mergedHead;

	while(l1 || l2){
		tail->next = (l1 && l2)? make_shared<ListNode<int>>(): nullptr;
		if(l1 && l2){
			if(l1->data < l2->data){
				tail->data = l1->data;
				l1 = l1->next;		
			}else{
				tail->data = l2->data;
				l2 = l2->next;
			}
		}else if(l2){			
			tail->data = l2->data;
			l2 = l2->next;
		}else{
			tail->data = l1->data;
			l1 = l1->next;
		}
		if(tail->next)
			tail = tail->next;
	}
	return mergedHead;
}

int main(){	
	// l1 = [2,7,10]
	// l2 = [3,8,9,11]
	//merged = [2,3,7,8,9,10,11]

	// shared_ptr<ListNode<int>> l1 = make_shared<ListNode<int>>(ListNode<int>{2,
	// 																make_shared<ListNode<int>>(ListNode<int>{7,
	// 																make_shared<ListNode<int>>(ListNode<int>{10,nullptr}
	// 																)})});
	// shared_ptr<ListNode<int>> l2 = make_shared<ListNode<int>>(ListNode<int>{3,
	// 																make_shared<ListNode<int>>(ListNode<int>{8,
	// 																make_shared<ListNode<int>>(ListNode<int>{9,
	// 																make_shared<ListNode<int>>(ListNode<int>{11,nullptr})
	// 																})})});

	shared_ptr<ListNode<int>> l1 = nullptr;
	shared_ptr<ListNode<int>> l2 = nullptr;

	shared_ptr<ListNode<int>> merged = mergeSortedLists(l1,l2);
	while(merged){
		cout<<merged->data<<endl;
		merged = merged->next;
	}

	return 0;
}

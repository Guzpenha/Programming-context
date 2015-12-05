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


shared_ptr<ListNode<int>> findCycle(shared_ptr<ListNode<int>> l){
	shared_ptr<ListNode<int>> slow, fast ;
	slow = fast = l ;

	while(fast){
		slow = slow->next;		
		fast = fast->next->next;
		if(fast == slow)
			break;
	}
	
	int sizeCycle = 1;
	slow = slow->next;
	while(slow!=fast){
		slow = slow->next;
		sizeCycle ++;
	}

	slow = fast = l;
	while(sizeCycle--)
		fast=fast->next;

	while(slow!=fast){
		slow= slow->next;
		fast= fast->next;
	}

	return slow;
}


int main(){	

	// l = [3,8,9,17,15,9,17,15...9,17,15...]
	shared_ptr<ListNode<int>> l2 = make_shared<ListNode<int>>(ListNode<int>{3,
																	make_shared<ListNode<int>>(ListNode<int>{8,
																	make_shared<ListNode<int>>(ListNode<int>{9,
																	make_shared<ListNode<int>>(ListNode<int>{17,
																	make_shared<ListNode<int>>(ListNode<int>{15,
																	make_shared<ListNode<int>>(ListNode<int>{11,nullptr})
																	})})})})});
	shared_ptr<ListNode<int>> cycleMaker = l2;
	while(cycleMaker->data !=15)
		cycleMaker= cycleMaker->next;			
	cycleMaker->next = l2->next->next;
	// while(l2){
	// 	cout<<l2->data<<endl;
	// 	l2= l2->next;
	// }

	shared_ptr<ListNode<int>> ans = findCycle(l2);
	if(ans)
		cout<<ans->data<<endl;
	return 0;
}

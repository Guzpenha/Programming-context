
//code from http://blog.csdn.net/chang_mu/article/details/41597611

#include <stdio.h>
#include <string.h>
#include <iostream>

#define maxn 1000002

int T[maxn], n;

int lowBit(int x) { return x & -x; }

void add(int v) {
	for(int pos = v; pos <= n; pos += lowBit(pos))
		++T[pos];
}

int getSum(int v) {
	int sum = 0, i;
	for(i = v; i > 0; i -= lowBit(i))
		sum += T[i];
	return sum;
}
using namespace std;
int main() {
	// for(int i=0;i<1000;i++)
		// cout<<i<<" "<<lowBit(i)<<endl;
	int t, i, ans, v;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		memset(T, 0, sizeof(int) * (n + 1));
		for(i = ans = 0; i < n; ++i) {
			scanf("%d", &v);
			add(v);
			if(getSum(v) != v) ++ans;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
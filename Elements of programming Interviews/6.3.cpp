#include <iostream>
#include <vector>
#include <limits>
#define REP(A,B) for(int A=0;A<B;A++)
#define PB push_back
#define SZ(X) (int)(X.size())
using namespace std;

int maxBatteryPower(vector<int> z){
	int ans=0, min_z = std::numeric_limits<int>::max();
	REP(i,SZ(z)){
		ans = max(ans,z[i]-min_z);
		min_z = min(min_z,z[i]);
	}
	return ans;
}


int main(){
	vector<int> z;
	int coord;
	while(cin>>coord)
		z.PB(coord);

	cout<<maxBatteryPower(z)<<endl;
	return 0;
}
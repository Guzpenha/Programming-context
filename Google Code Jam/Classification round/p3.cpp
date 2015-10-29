#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int product(int a, int b){
	//absx = |x|
	int ans, absa = abs(a), absb = abs(b);
	if((absa == 1)||(absb == 1)) return a*b;
	
	if(absa == absb) ans = -1;
	else
		if(absa == 2){
			if(absb == 3) ans = 4;  
			else if(absb == 4) ans = -3;
		}
		else
			if(absa == 3){
				if(absb == 2) ans = -4;
				if(absb == 4) ans = 2;
			}
			else
				if(absa == 4){
					if(absb == 2) ans = 3;
					if(absb == 3) ans = -2;
				}
	if(a < 0) ans *= -1;
	if(b < 0) ans *= -1;
	return ans;
}

int quart(char c){
	if(c == 'i') return 2;
	if(c == 'j') return 3;
	if(c == 'k') return 4;
}

 // 1 = 1
 // i = 2
 // j = 3
 // k = 0
//stage = 1, 2, 3, 4 for ijk1
int main(){

	int t, l, x, stage, current, xcounter, index, target;
	bool ans;
	string input, copy, ans_s;

	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> l >> x;
		cin >> input;
		stage = 0;
		index = 0;
		copy = input;
		ans = true;
		target = 2;
		while((stage != 3)and(ans)){
			xcounter = 1;
			if(target == 5) target = 1;
			current = quart(input[index]);
			while(current != target){
				current = product(current, quart(input[index]));
				if((index+1)%l == 0){
					if((xcounter != 4)and(xcounter <= x)){
						input += copy;
						xcounter++;
					}
					else{
						ans = false;
						break;
					}
				}
				index++;
			}
			target++;
			stage++;
		}
		if(ans) ans_s = "YES";
		else ans_s = "NO";
		cout << "Case #" << tt << ": " << ans_s << endl;
	}

	return 0;
}
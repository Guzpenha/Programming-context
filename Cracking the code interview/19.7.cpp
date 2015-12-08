
 new code
 samples
 recent codes
sign in

 
edit fork	download copy
#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits.h> 
using namespace std;
 
int largestSumN3(vector<int> a){
	int largestSum =0;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<i;j++){
			int sum =0;
			for(int k=j;k<i;k++){
				sum+=a[k];
			}
			largestSum=max(sum,largestSum);
		}
 
	}
	return largestSum;
}
 
int largestSumN2(vector<int> a){
	int largestSum =0;
	for(int i=0;i<a.size();i++){
		int sum =0;
		for(int j=i;j<a.size();j++){			
			     sum+=a[j];
	    		 largestSum= max(sum,largestSum);
		}
	}
	return largestSum;
}
 
 
int largestUsingMid(vector<int>a , int left, int right,int mid){
	int largestSumLeft = INT_MIN,largestSumRIght = INT_MIN;
	int sum=0;
	for(int i=mid;i<=right;i++){		
		sum+=a[i];
		largestSumRIght = max(largestSumRIght,sum);
	}
	sum=0;
	for(int i=mid-1;i>=left;i--){		
		sum+=a[i];
		largestSumLeft = max(largestSumLeft,sum);
	}
	return largestSumLeft+ largestSumRIght;
}	
 
 
int largestSumDC(vector<int> a, int left, int right){
	if(left == right)
		return a[left];
	int mid = left + ((right-left)/2);
	int leftLargest = largestSumDC(a,left,mid);
	int rightLargest = largestSumDC(a,mid+1,right);
	int largestMid = largestUsingMid(a,left,right,mid);
 
	int answer = max(leftLargest,rightLargest);
	return max(answer,largestMid);
 
}
 
int largestSumKadane(vector<int>a ){
	int answer=INT_MIN, sum=0;
	for(int i=0;i<a.size();i++){
		sum+=a[i];
		answer = max(answer,sum);
		sum = max(sum,0);	
	}
	return answer;
}
int main() {
	vector<int> test;
	test.push_back(2);
	test.push_back(-8);
	test.push_back(3);
	test.push_back(-2);
	test.push_back(4);
	test.push_back(-10);
	// cout<<largestSumN3(test)<<endl;
	// cout<<largestSumN2(test)<<endl;
	 //cout<<largestSumDC(test,0,test.size())<<endl;
	 cout<<largestSumKadane(test)<<endl;
 
	return 0;
}
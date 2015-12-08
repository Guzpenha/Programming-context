#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void mergeSortArrays(vector<int> &A, vector<int> B, int lastIndexA){
  int lastIndexB = B.size()-1;
  int lastIndexBoth = A.size()-1;
  while(lastIndexA>=0 &&  lastIndexB>=0){    
    if(A[lastIndexA] > B[lastIndexB]){
        A[lastIndexBoth--] = A[lastIndexA--];
     }else{
        A[lastIndexBoth--] = B[lastIndexB--]; 
     }
  }
  while(lastIndexB>=0){
     A[lastIndexBoth--] = B[lastIndexB--];
  }
}


int main(){ 
  vector<int> A;  
  A.push_back(2);
  A.push_back(3);
  A.push_back(4);
  A.push_back(6);
  A.push_back(7);
  A.push_back(11);
  A.push_back(0);
  A.push_back(0);
  A.push_back(0);
  A.push_back(0);
  vector<int> B;
  B.push_back(1);
  B.push_back(5);
  B.push_back(8);
  B.push_back(15);
  mergeSortArrays(A,B,5);
  for(int i=0;i<A.size();i++){
    cout<<A[i]<<endl;
  }
  return 0;
}


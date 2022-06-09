#include <bits/stdc++.h>
#include "02_subset_sum.cpp"
using namespace std;

bool eqlsumpartition(int arr[],int n){
	int sum = 0;
	for(int i = 0; i<n; i++){
		sum += arr[i];
	}

	//if sum of elements of an array is odd, then partition is not possible.
	if(sum%2 != 0)	return false;

	return subsetSum(arr,sum/2,n);	// sum(subset) == sum(arr)/2 is present or not.
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}
	
	if(eqlsumpartition(arr,n)){
		cout<<"True"<<endl;
	}	
	else{
		cout<<"False"<<endl;
	}
}
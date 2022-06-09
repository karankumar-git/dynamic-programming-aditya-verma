#include <bits/stdc++.h>
using namespace std;
// in subset_sum, we get answer in boolean.
// to count the subset we just have to change the " || " (OR) to " + " (plus)
// remaining code is same.
int subsetOfGivenSum(int arr[],int sum,int n){
	int t[n+1][sum+1];

	for(int i = 0; i< sum+1; i++){
		t[0][i] = 0;
	}
	for (int i = 0; i < n+1; ++i){
		t[i][0] = 1;
	}

	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<sum+1; j++){
			if(arr[i-1]<=j){
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}
	int sum; cin>>sum;
	cout<<subsetOfGivenSum(arr,sum,n);	
}
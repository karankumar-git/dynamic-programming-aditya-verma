#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[],int sum,int n){
	bool t[n+1][sum+1];
	//case-1: n == 0 , sum = 1,2,3...
	//if there is no element in arr, but sum is 0. then it is possible(true).
	//case-2: sum == 0, n = 0,1,2...
	//if the sum is 0 and arrays contains elements.. then it can be possible(empty array)(true).


	//i = n , j = sum
	for(int i = 0; i<n+1; i++){
		for(int j = 0 ; j< sum+1; j++){
			//No element is arr
			if(i==0) t[i][j] = false;

			//Sum is 0
			if(j==0) t[i][j] = true;
		}
	}
	for(int i = 1; i<n+1; i++){
		for(int j = 1 ; j< sum+1; j++){
			if(arr[i-1]<=j){
				t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j];	//use OR to find max and use AND to find min				
			}
			else{
				t[i][j] = t[i-1][j];	
			}
		}
	}
	return t[n][sum];
}

// int main(){
// 	int arr[] = {2,3,7,8,10};
// 	int sum ;
// 	cin>>sum;
// 	cout<<subsetSum(arr,sum,5) ? "YES" : "NO";
// }
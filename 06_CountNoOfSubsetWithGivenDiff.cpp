#include <bits/stdc++.h>
using namespace std;

int countNoOfSubset(vector<int> arr, int n){
	int sum = 0;
	for(int x: arr){
		sum += x;
	}

	return subsetSum()
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0 ; i<n; i++){
		int temp; cin>>temp;
		v.push_back(temp);
	}	
	int diff;
	cin>>diff;

	cout<<countNoOfSubset(v,n)<<endl;
}
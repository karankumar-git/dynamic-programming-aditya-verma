#include <bits/stdc++.h>
using namespace std;

int maxprofit(int wt[],int val[],int W,int n){
	// if we have no item or if the weight of bag is 0.
	if(n == 0 or W == 0){
		return 0;
	}
	
	int itemW = wt[n-1];

	// Item can be store in bag.
	if(itemW <= W){	
		return max(val[n-1] + maxprofit(wt,val,W-itemW,n-1),maxprofit(wt,val,W,n-1));
	}
	// Item can't be store in bag. Try next
	else{ 
		return maxprofit(wt,val,W,n-1);
	}
}

int static mp[4][4];


int maxprofitdp(int wt[],int val[],int W,int n){

	//if given itemWt and bag's weight has solve previously;
	if(mp[n][W] != -1){
		return mp[n][W];
	}

	int itemW = wt[n-1];

	//if item can be store in bag.
	if(itemW <= W){

		mp[n][W] = max(val[n-1] + maxprofitdp(wt,val,W-itemW,n-1),maxprofitdp(wt,val,W,n-1));
		return mp[n][W];
	}
	else{
		mp[n][W] = maxprofitdp(wt,val,W,n-1);
		return mp[n][W];
	}
}

int knapsacktopdown(int wt[],int val[],int W,int n){
	int m[n+1][W+1]={0};
	for(int i = 0; i<W+1;i++){
		m[0][i] = 0;
	}
	for(int i = 0; i<n+1;i++){
		m[i][0] = 0;
	}
	for(int i = 1 ; i<n+1; i++){
		for(int j = 1; j<W+1; j++){
			if(wt[i-1] <= j){
				m[i][j] = max(val[i-1] + m[i-1][j-wt[i-1]],m[i-1][j]);
			}
			else{
				m[i][j] = m[i-1][j];
			}
		}
	}	
	return m[n][W];

}


int main(){
	// Initiate DP Table with -1;
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			mp[i][j]=-1;
		}
	}
	// for(int i = 0; i<4; i++){
	// 	for(int j = 0; j<4; j++){
	// 		cout<<mp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int val[3] = { 60, 100, 120};
	int wt[3] = { 10, 20, 30 };
	cout<<knapsacktopdown(wt,val,50,3);
}
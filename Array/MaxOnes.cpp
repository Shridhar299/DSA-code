#include <bits/stdc++.h>
using namespace std;

void MaxOnes(int arr[], int n){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(arr[i]==1){
			cnt++;
		}
		
		if(arr[i]!=1){
			cnt=0;
		}
	}
	cout<<cnt;
}
int main(){
	int n;
	cin>> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	MaxOnes(arr,n);
	return 0;
}

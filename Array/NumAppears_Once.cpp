/* Every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n){
	
	for(int i=0; i<n; i++){
		int num=arr[i];
		int cnt=0;
		
		for(int j=0; j<n; j++){
			if(arr[j]==num){
				cnt++;
			}
		}
		
		if(cnt==1){
			cout<<num<<" ";
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		solve(arr,n);
	}
	return 0;
}

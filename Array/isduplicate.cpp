#include <bits/stdc++.h>
using namespace std;

bool isduplicate(int arr[], int n){
	for(int i=0; i<n;i++){
		for(int j=i+1; j<n ; j++){
			if(arr[i]==arr[j]){
				return true;
			}
		}
	}
	return false;
}
int main() {
    
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        
        string result = isduplicate(arr, n) ?   "True" :   "False";
        cout<<result<<endl;
    
    return 0;
}

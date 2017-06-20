#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool findpair(int arr[],int n ){
	map<int, pair<int,int> > hash;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			
			int sum = arr[i]+arr[j];
			if(hash.find(sum) == hash.end()){
				hash[sum] = make_pair(i,j);
			}
			else{
				pair<int,int>pp = hash[sum];
				
				cout << "(" << arr[pp.first] << ", " << arr[pp.second]
                     << ") and (" << arr[i] << ", " << arr[j] << ")n";
                return true;
			}
		}
	}
	cout << "No pairs found";
    return false;		
}

int main()
{
    int arr[] = {7,6,5,4,3,2,1};
    int n  =  sizeof arr / sizeof arr[0];
    findpair(arr, n);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int min(long long int a , long long int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}


int main()
{
	int t;
	cin>>t;
	
	while(t--){
		long int n,k;
		cin>>n>>k;
		//vector<long long int> a;
		long long int a[n];
		for(long int i=0;i<n;i++){
			cin>>a[i];
		}
		
				
		for(long long int i=1;i<=k;i++){
			
			long long int* pbegin = a;                          
		    long long int* pend = a+sizeof(a)/sizeof(long long int);
			long long int first = 0;
			long long int last = n-i;
			long long int minvalue = min(a[first],a[last]);
			a.remove(pbegin, pend, minvalue);
			/*
			if (minvalue == a[first]){
				a.erase(std::remove(a.begin(), a.end(), minvalue), a.end());
				//remove first and shift array
				a.erase(a.begin() + first);
			}else if(minvalue == a[last]){
				//cout<<'ss'<<endl;
				a.erase(a.begin() + last);
			}
			* */
		}	
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<' ';
		}
		
		long long int res = a[0] * a[n-k];
		cout<<res<<endl;
	
	}
 
    return 0;
}

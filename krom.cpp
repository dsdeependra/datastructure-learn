#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        
        string arr[n];
        stack<int> s;
        for(long int i=0;i<n;i++){
            cin >> arr[i];
        }
        long int res=0;
        long int j,k;
        for(long int i=n-1;i>=0;i--){
			
			if(arr[i] != "PLUS" && arr[i] != "MINUS")
				j=0;
			
			if(arr[i] == "ZERO"){
				 j= 0;
			 }
			else if(arr[i] == "ONE") j=1;
			else if(arr[i] == "TWO") j=2;
			else if(arr[i] == "THREE") j=3;
			else if(arr[i] == "FOUR") j=4;
			else if(arr[i] == "FIVE") j=5;
			else if(arr[i] == "SIX") j=6;
			else if(arr[i] == "SEVEN")	j=7;
			else if(arr[i] == "EIGHT")	j=8;
			else if(arr[i] == "NINE")	j=9;
			
			if(i ==0)
				k=j;
				 
			
				 
			if(arr[i] == "PLUS"){
				s.push(110);
				
			}
			else if(arr[i] == "MINUS")		
				s.push(111);
			else{
				s.push(j);	 
			}
			
		    if(k>=0){
				res =k;
			}
			
			
		}
		
		while(!s.empty()){
			int temp = s.top();
			s.pop();
			
			if(temp == 110){
				
				res = res+s.top();
				s.pop(); 
			}
			else if(temp == 111){
				res = res - s.top();
				s.pop();
			}
			
		}
			
		cout<<res<<endl;
        
    }
    return 0;
}

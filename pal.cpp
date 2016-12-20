#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	
    int n;
    cin>>n;
    while(n--){
    	string s;
    	cin>>s;
    	int flag=1;
    	int len = s.length();
    	
    	int middle = len/2;
    	int j=len-1;
 
    	for(int i=0;i<middle;i++,j--){
			
    		if(s[i] == s[j] && flag==1){
    			flag=1;
    		}
    		else{
    			flag=0;
    		}
    	}
    	
    	if(flag==0 && len >1){
    		cout<<"NO"<<endl;
    	}
    	else if(len==1){
    		cout<<"YES ODD"<<endl;
    	}
    	else{
    		if(len % 2 == 0){
    			cout<<"YES EVEN"<<endl;
    		}
    		else{
    			cout<<"YES ODD"<<endl;
    		}
    	}
	}
    	
    	
    return 0;
}

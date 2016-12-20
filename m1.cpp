#include <iostream>
#include <algorithm>

using namespace std;
int iseven(int count){
	if(count %2 ==0){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	
	int n;cin>>n;
	while(n--){
		int s;
		cin>>s;
		int a[s];
		for(int i=0;i<s;i++){
			cin>>a[i];
		}
		int count =0;
		int min= *min_element(a,a+s);
		for(int i=0;i<s;i++){
			if(a[i] == min){
				count++;
			}
		}
		if(!iseven(count)){
			cout<<"Unlucky"<<endl;
		}
		else{
			cout<<"Lucky"<<endl;
		}
	}
	return 0;
}

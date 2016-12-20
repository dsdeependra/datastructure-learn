#include <iostream>
#include <map> 
using namespace std;

int main()
{
	map<long int , string>m;
	
    int n;
    cin >> n;
  
    for(int i=0;i<n;i++){
    	long int x;
    	string name;
    	cin>>x;
    	cin >> name;
    	m.insert(pair<long int, string>(x,name));
    }
    
    int q;
    cin>> q;
    while(q--){
    	long int z;
    	cin >> z;
    	
    	string name_res = m.find(z)->second;
    	cout << name_res<<endl;
    }
    return 0;
}

#include<iostream>
#include<map>

using namespace std;

int oddOccuring(int arr[] , int n){
	map<int , int> m;
	for(int i =0; i<n;i++){
		pair<map<int,int>::iterator,bool>ret;
		ret=m.insert(pair<int,int>(arr[i],1));
		if(ret.second == false){
			// key already existed'
			ret.first->second +=1;
		}
	}
	//m<int, int>::iterator it =m.begin();
	map<int,int>::iterator it ;//= m.begin();
	for (it=m.begin(); it!=m.end(); ++it){
		if(it->second /2 !=0){
			return it->second;
		}
		//std::cout << it->first << " => " << it->second << '\n';
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,2,3,1,5,11,165,11,6,7,8,9,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int num = oddOccuring(arr,size);
	cout<<num<<endl;
	return 0;
}

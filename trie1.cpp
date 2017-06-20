#include<iostream>
#include<bits/stdc++.h>


#define SIZE (26)
#define char_int(c)((int)c-(int)'a')
#define int_char(c)((char)c + (char)'a')

using namespace std;

struct trieNode {
	trieNode *Child[SIZE];
	bool leaf;
};

trieNode *getNode(){
	trieNode *newNode = new trieNode;
	newNode->leaf = false;
	for(int i=0;i<SIZE;i++){
		newNode->Child[i]= NULL;
	}
	
	return newNode;
}

void insert(trieNode *root, char *key){
	int n = strlen(key);
	trieNode *pChild = root;
	
	for(int i=0;i<n;i++){
		int index = char_int(key[i]);
		if(pChild->Child[index] == NULL){
			pChild->Child[index] = getNode(); // assign a new node to the next char
			
			pChild = pChild->Child[index];  // point to the new node
		}
	} 
	pChild->leaf= true;
}

void SearchWord(trieNode *root, bool Hash[], string str){
	if(root->leaf == true){
		cout<<str<<endl;
	}
	
	for(int k=0;k<SIZE;k++){
		if(Hash[k] == true && root->Child[k] !=NULL){
			char c= int_char(k);
			//recursively search for the next character and then find the word
			
			SearchWord(root->Child[k],Hash,str+c);
		}
	}
}

void printAllWords(char arr[],trieNode *root,int n){
	bool Hash[SIZE];
	
	for(int i=0;i<n;i++){
		Hash[char_int(arr[i])]= true;
	}
	
	trieNode *pChild = root;
	string str="";
	for(int j=0;j<SIZE;j++){
		// we start searching for a word in a dictionary if we foiund a character is a child of a trie root
		if(Hash[j] == true && pChild->Child[j]){
			str = str + (char)int_char(j);
			SearchWord(pChild->Child[j],Hash,str);
			str="";
		}
	}
}

int main(){
	char dict[][20]={"g","bat","me","boy","goal","eat"};
	char arr[] = {'a','t','m','b','e'};
	trieNode *root = getNode();
	
	// insert all the dictionary to trie
	int n= sizeof(dict)/sizeof(dict[0]);
	for(int i=0;i<n;i++)
		insert(root,dict[i]);
	
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printAllWords(arr,root,arr_size);
	
	return 0;
	
	
}

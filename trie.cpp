#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct trieNode{
	int wordsCount;
	int prefixCount;
	struct trieNode *edges[];
};

initializeTrie(trieNode* root){
	root->wordsCount = 0;
	root->prefixCount = 0;
	for(int i=0; i<26;i++){
		edges[i] = NULL;
	}
}

void addWord(trieNode* root , string word){
	if(word.empty()){
		root->wordsCount++;
	}
	else{
		root->prefixCount++;
		char k = word[0];
		if(!edges[k] == NULL){
			edges[k] = 
		}
	}
} 

int main(){
	
	trieNode*  root = (struct trieNode*)malloc(sizeof(struct trieNode));
	initializeTrie(root);
	return 0;
}

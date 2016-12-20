#include <iostream>
#include <cstdlib>
using namespace std;

//replace every element with the least greater element on its right side in an array
struct node{
	int data;
	node *left,*right;
};

node* Newnode(int data){
	node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode ->left = NULL;
	newnode ->right = NULL;
	return newnode;
}

void insert(node*& root , int data , node*& succ){
	if(root == NULL)
		root = Newnode(data);
	if(data < root->data){
		succ = root;
		insert(root->left, data, succ);
	}
	else if(data > root->data)
		insert(root->right, data, succ);
}

void replace (int arr[], int n){
	node *root= NULL;
	for(int i=n-1;i>=0;i--){
		node *succ = NULL;
		insert(root,arr[i],succ);
		if(succ){
			arr[i] = succ->data;
		}
		else
			arr[i] = -1;
	}
}

int main(){
	
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
                  43, 3, 91, 93, 25, 80, 28 };
    int n = sizeof(arr)/ sizeof(arr[0]);
 
    replace(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}




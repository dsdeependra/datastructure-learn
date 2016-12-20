#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
struct node {
	long int data;
 	node *left;
 	node *right;
 };

node *newBinaryTree(long int data){
 	node *newnode = (struct node*)malloc(sizeof(struct node));
 	newnode->data = data;
 	newnode->left=NULL;
 	newnode->right = NULL;
 	return newnode;
 }


void addtobinarytree(node* root, long int data){
 	if(root == NULL){
		return;
 	}
 	if(root->data > data){
 		if(root->left != NULL){
 			addtobinarytree(root->left , data);
 		}
 		else{
 			root->left = newBinaryTree(data);
 		}
 	}
 	if(root->data < data){
 		if(root->right !=NULL){
 			addtobinarytree(root->right ,data);
 		}
 		else{
 			root->right = newBinaryTree(data);
 		}
 	}
 }
 node *findNodeFromData(node *root,long int data){
	node *returnroot;
	if(root->data == data)
		returnroot =root;
	if(root->left !=NULL){
		findNodeFromData(root->left,data);
	}
	if(root->right !=NULL){
		findNodeFromData(root->right,data);
	}
	//return NULL;
	return returnroot;
}
void findPreSuc(node* root, node*& pre, node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}


int main()
{
	 int n;
	 cin>>n;
	 long int A[n];
	 for(int i=0;i<n;i++){
	 	cin>>A[i];
	 }
	 long int x,y;
	 cin>>x>>y;
	 //int numbertofind;
	 //cin>>numbertofind;
	 node *newnode = newBinaryTree(A[0]);
	 for(int i=0;i<n;i++){
		 int data = A[i];
         addtobinarytree(newnode,data);
     }
     node* pre = NULL;
     node* suc = NULL;
     findPreSuc(newnode,pre,suc,y);
     if(y>pre->data){
         cout<<pre->data<<endl;
     }
     else{
         cout<<y<<endl;
     }
     
    
    return 0;
}

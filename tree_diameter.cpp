#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node {
	int data;
	node *left,*right;
};
node *createnode(int data){
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int height(struct node* node)
{
   if(node == NULL)
       return 0;
   return 1 + max(height(node->left), height(node->right));
} 
int diameter(struct node * tree)
{
  
   if (tree == NULL)
     return 0;
 
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);

  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 
 

void inorder(node *root){
	if(root->left !=NULL){
		inorder(root->left);
	}
	cout<<root->data<<" ";
	if(root->right !=NULL){
		inorder(root->right);
	}
}
int main()
{
    int n;
    cin>>n;
    int root_data;
    cin>>root_data;
    node *root = createnode(root_data);
    for(int j =0;j<n-1;j++){
    	string s;
    	cin>>s;
    	int node_data;
    	cin>>node_data;
    	node *temp = root;
    	for(unsigned i =0;i<=s.length();i++){
    		
    		if(s[i]=='L'){
    			
    			if(temp->left !=NULL){
    				temp = temp->left;
    			}
    			else{
    				temp->left = createnode(node_data);
    			}
    		}
    		else if(s[i] == 'R'){
    			if(temp->right !=NULL){
    				temp=temp->right;
    			}	
    			else{
    				temp->right = createnode(node_data);
    			}
    		}
    	}
    	//cout<<'ss'<<endl;
    }
    
    int dm = diameter(root);
    cout<<dm<<endl;
    //inorder(root);
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <climits>
#include <stack>
using namespace std;
struct node {
	int data;
 	node *left;
 	node *right;
 };

 node *newBinaryTree(int data){
 	node *newnode = (struct node*)malloc(sizeof(struct node));
 	newnode->data = data;
 	newnode->left=NULL;
 	newnode->right = NULL;
 	return newnode;
 }
 void preorder(node *root){
 	cout<<root->data<<' ';
 	if(root->left !=NULL){
 		preorder(root->left);
 	}
 	if(root->right !=NULL){
 		preorder(root->right);
 	}
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


//


 void addtobinarytree(node* root, int data){
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
 
node *findNodeFromData(node *root,int data){
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

int findMinValue(node *root){
	int returndata;
	if(root !=NULL){
		if(root->left != NULL){
			findMinValue(root->left);
		}
		else{
			
			returndata = root->data;
		}
	}
	return returndata;
}

int isBSTUtil(node *root, int min,int max ){
	//we can do it by finding the max value in left subtree and that should be less than root->data and min value of right subtreee should be greater than root->data
	
	if(root == NULL)
		return 1;
	if(root->data <min || root->data >max)
		return 0;
	return (isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max));
}
int isBST(node *root){
	
		return isBSTUtil(root,INT_MIN,INT_MAX);
	
}

unsigned long int binomialCoeff(unsigned int n, unsigned int k){
	unsigned long int res=1;
	//since c(n,k) = c(n,n-k)
	if(k>n-k)
		k=n-k;
	for(unsigned int i=0;i<k;++i){
		res *= (n-i);
		res /= (i+1);
	}
	return res;
	
	
}
unsigned long int catalan(unsigned int n){
	unsigned long int c = binomialCoeff(2*n,n);
	return c/(n+1);
}
unsigned long int numberOfBinaryTree(int n){
	return catalan(n);
}
node *kSmallestNumber(node *root, int k){
	stack<node*>s;
	node *temp = root;
	while(temp !=NULL){
		s.push(temp);
		temp=temp->left;
	}
	while( temp = s.top()){
		s.pop();
		if(!--k){
			break;
		}
		if(temp->right !=NULL){
			temp= temp->right;
			while(temp !=NULL){
				s.push(temp);
				temp=temp->left;
			}
		}
	}
	return temp;
}
int diameter(node *root){
	if(root == NULL)
		return 1;
	if(root->left !=NULL || root->right != NULL){
		return diameter(root->left) +1 + diameter(root->right) ;
	}
}
int main()
{
	 int n;
	 cin>>n;
	 int A[n];
	 for(int i=0;i<n;i++){
	 	cin>>A[i];
	 }
	 
	 //int numbertofind;
	 //cin>>numbertofind;
	 node *newnode = newBinaryTree(A[0]);
	 for(int i=0;i<n;i++){
		 int data = A[i];
         addtobinarytree(newnode,data);
     }
     
     //node *currentroot = findNodeFromData(newnode,numbertofind);
     //preorder(currentroot);
     
     //cout<<findMinValue(newnode);
     //cout<<endl;
     //inorder(newnode);
     
     //cout<<isBST(newnode);
     //cout<<numberOfBinaryTree(n);
     
     node * test = kSmallestNumber(newnode,2);
     cout<<test->data;
    //cout << "Hello World!" << endl;
    return 0;
}

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int v;
	node *left, *right;
};

struct node *rightRotate(struct node* tree){
	struct node *temp = tree->right;
	 tree->right = temp->left;
	 temp->left = tree;
	 return temp;
} 

struct node *leftRotate(struct node* tree){
	struct node *temp = tree->left;
	 tree->left = temp->right;
	 temp->right = tree;
	 return temp;
}

struct node* leftRightRotate(struct node* tree){
	tree->left = rightRotate(tree->left);
	return leftRotate(tree);
}

struct node* rightleftRotate(struct node* tree)
{
	tree->right = leftRotate(tree->right);
	return rightRotate(tree);
}

int getHeight(struct node* tree){
	if(tree == NULL){
		return 0;
	}
	int l =  getHeight(tree->left);
	int r =  getHeight(tree->right);
	return max(l,r)+1;
}

struct node* insert(struct node * tree,int val){
	if(tree == NULL){
		tree = new node();
		tree->left = NULL;
		tree->right = NULL;
		tree->v = val;
		return tree;
	}
	if(val < tree->v){
		tree->left = insert(tree->left, val);
		int l = getHeight(tree->left); 
		int r = getHeight(tree->right);
		if(l -r>=2){
			//进行旋转 
			if(val < tree->left->v){
				tree = leftRotate(tree);
			}else{
				tree = leftRightRotate(tree);
			}
		}
	}else{
		tree->right = insert(tree->right, val);
		int l = getHeight(tree->left); 
		int r = getHeight(tree->right);
		if(r -l>=2){
			//进行旋转 
			if(val > tree->right->v)
				tree = rightRotate(tree);//发生问题在右子树的右边 
			else 
				tree = rightleftRotate(tree); //发生问题在右子树的左边
		}
	}
	return tree;
}

int main(){
	int n;
	scanf("%d",&n);
	struct node *root = NULL;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		root = insert(root,a);
		
	}
	printf("%d",root->v);
}

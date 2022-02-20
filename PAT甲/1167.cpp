#include "iostream"
#include "math.h"
#include "vector"
using namespace  std;
struct Node{
    int val;
    struct Node * left;
    struct Node * right;
};
int findMin(int nums[], int size){
    int mini = 0 ;
    for (int i=1;i<size; i++){
        if (nums[mini] > nums[i]){
            mini = i;
        }
    }
    return mini;
}

Node * build(int nums [],int size){
    if(size <= 0){
        return nullptr;
    }
    int mini = findMin(nums, size);
    Node *root = (Node *)malloc(sizeof(Node));
    root->val = nums[mini];
    root->left = build(nums, mini);
    root->right = build(nums+mini+1, size-mini-1);
    return root;
}


int main(){
    int n;
    cin >> n;
    int inorder[n];
    for(int i=0; i<n; i++){
        cin >> inorder[i];
    }
    Node * root = build(inorder, n);
    vector<Node *> vec;
    vec.push_back(root);
    cout << root->val;
    while (!vec.empty()){
        Node * node = vec.back();
        vec.pop_back();
        if(node->left != nullptr){
            vec.insert(vec.begin(),node->left );
            cout <<" "<<node->left->val;
        }
        if(node->right != nullptr){
            vec.insert(vec.begin(),node->right );
            cout <<" "<<node->right->val;
        }
    }

}
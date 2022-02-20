#include "iostream"
#include "vector"
using namespace std;

int inorder[31], postorder[31];
int n ;

struct Node{
    int num;
    struct Node *left,*right;
};
int find(const int nums[], int size, int val){
    for (int i=0;i<size; i++){
        if (val == nums[i]){
            return i;
        }
    }
}

Node * buildTree(int afterOrder[],int inOrder[], int size){
    if(size <= 0){
        return nullptr;
    }
    Node *root = (Node *)malloc(sizeof(Node));
    int postIndex = find(inOrder,size,afterOrder[size-1]);
    root->num = afterOrder[size-1];
    root->left = buildTree(afterOrder,inOrder, postIndex);
    root->right = buildTree(afterOrder+postIndex,inOrder+ postIndex + 1, size - postIndex - 1);
    return root;
}

int main(){
    cin >>n;
    vector<Node *> vec1,vec2;
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin >> inorder[i];
    }
    for(int i=0;i<n;i++){
        cin >> postorder[i];
    }
    Node* root  = buildTree(postorder,inorder,n);
    bool flag = true;
    bool first = true;
    vec1.insert(vec1.begin(),root);
    while(!vec1.empty()  || !vec2.empty()){
        temp.clear();
        while(!vec1.empty()){
            Node * node = vec1[vec1.size()-1];
            temp.push_back(node->num);
            vec1.pop_back();
            if(node->left != nullptr){
                vec2.insert(vec2.begin(), node->left);
            }
            if(node->right != nullptr){
                vec2.insert(vec2.begin(), node->right);
            }
        }
        if(flag){
            std::reverse(temp.begin(), temp.end());
        }
        flag = !flag;
        vec1 = vec2;
        vec2.clear();
        if(first){
            cout << temp[0];
            first = false;
        }else{
            for(int j=0;j< temp.size(); j++){
                cout<<" "<<temp[j];
            }
        }
    }
    return 0;
}
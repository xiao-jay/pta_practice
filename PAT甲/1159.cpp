#include "iostream"
#include "map"
using namespace  std;
typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *father;
    int depth;
}Node;

map<int ,  Node *> mp ;
bool full = true;
int  Find(int array[], int size, int v){//找的始终是中序
    for (int i = 0; i < size; i++){
        if (array[i] == v){
            return i;
        }
    }
    return -1;
}
Node * BuildTree(int afterorder[], int inorder[], int size, int depth){
    if (size == 0){
        return  nullptr;
    }
    int rootValue = afterorder[size-1];
    int leftSize = Find(inorder, size, rootValue);//i的返回值就是左子树的个数
    //根
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = rootValue;

    //左子树
    root->left = BuildTree(afterorder , inorder, leftSize, depth+1);
    if(root->left != nullptr){
        root->left->father = root;
    }
    //右子树
    root->right = BuildTree(afterorder + leftSize, inorder + leftSize + 1, size - 1 - leftSize, depth+1);
    if (root->right != nullptr){
        root->right ->father = root;
    }

    mp[rootValue] = root;
    if ((root->left && !root->right) || !root->left && root->right) full = false;
    root->depth = depth;
    return root;
}

int main(){
    int n;
    cin >>n;

    int postorder[n],inorder[n];
    for (int i=0;i<n;i++){
        cin >>postorder[i];
    }
    for (int i=0;i<n;i++){
        cin >>inorder[i];
    }
    Node * root = BuildTree(postorder,inorder, n, 0);

    int n2;
    cin >> n2;
    getchar();
    while (n2--){
        string s;
        int a,b ;
        getline(cin, s);
        if (s.find("root") != string::npos){
            sscanf(s.c_str(), "%d is the root", &a);
            if (root->value == a){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s.find("siblings") != string::npos){
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            if (mp[a]->father == mp[b]->father){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s.find("parent") != string::npos){
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            if(mp[b]->father == mp[a]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s.find("left") != string::npos){
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            if (mp[b]->left == mp[a]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else if(s.find("right") != string::npos){
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            if (mp[b]->right == mp[a]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else if(s.find("level") != string::npos){
            sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
            if (mp[b]->depth == mp[a]->depth) cout << "Yes" << endl;
            else cout << "No" << endl;

        }else if(s.find("full") != string::npos){
            if (full) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
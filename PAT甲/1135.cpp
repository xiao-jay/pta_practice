#include "iostream"

using namespace std;

int m;
int num[31];
bool is_valid;
struct Node {
    Node *left, *right;
    int num;
    bool isRed;
};

Node *buildNode(int a, bool is_red) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = a;
    node->isRed = is_red;
    node->right = nullptr;
    node->left = nullptr;
    return node;
};

Node *build(Node *root, int a, bool is_red) {
    if (root == nullptr) {
        return buildNode(a, is_red);
    }
    if (a > root->num) root->right = build(root->right, a, is_red);
    else root->left = build(root->left, a, is_red);
    return root;

}

int blackNodeNums = 0;

void dfs(Node *root, int blackNodeNum) {
    //如果知道错的就直接return
    if (is_valid) return;

    if (root == nullptr) {
        if (blackNodeNums == 0) blackNodeNums = blackNodeNum;
        else if (blackNodeNums != blackNodeNum) is_valid = true;
        return;
    }
    if (!root->isRed) {
        dfs(root->left, blackNodeNum + 1);
        dfs(root->right, blackNodeNum + 1);
    } else {
        dfs(root->left, blackNodeNum);
        dfs(root->right, blackNodeNum);
    }
}

void dfsRed(Node *root) {
    if (root->left != nullptr) {
        if (root->isRed && root->left->isRed) is_valid = true;
        else dfsRed(root->left);
    }
    if (root->right != nullptr) {
        if (root->isRed && root->right->isRed) is_valid = true;
        else dfsRed(root->left);
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> num[i];
        }
        is_valid = false;
        blackNodeNums = 0;
        if (num[0] < 0) {
            cout << "No" << endl;
            continue;
        }
        Node *root = nullptr;
        for (int i = 0; i < m; i++) {
            if (num[i] < 0) root = build(root, -num[i], true);
            else root = build(root, num[i], false);
        }
        dfs(root, 0);
        if (is_valid) {
            cout << "No" << endl;
            continue;
        }
        dfsRed(root);
        if (is_valid) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}
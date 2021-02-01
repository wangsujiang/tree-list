#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:

    bool compare(TreeNode* a, TreeNode* b){
        if ((a == nullptr && b !=nullptr) || (a != nullptr && b ==nullptr)){
            return 0;
        }
        else if (a == nullptr && b ==nullptr){
            return 1;
        }
        else {
            if (a->val == b->val){
                return compare(a->left, b->left) && compare(a->right, b->right);
            } else {
                return 0;
            }
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ((s == nullptr && t !=nullptr) || (s != nullptr && t ==nullptr)){
            return 0;
        }else if (s == nullptr && t ==nullptr){
            return 1;
        }else {
            return compare(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};

TreeNode *newnode(int val){
    TreeNode *node = new TreeNode;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TreeNode* VecToTreenode(vector<int> v, int len, int index){
    if (index >= len) return nullptr;

    TreeNode* root = new TreeNode;
    root = newnode(v[index]);

    root->left = VecToTreenode(v, len, 2*index+1);
    root->right = VecToTreenode(v, len, 2*index+2);
    return root;
}

int main(){
    int n,m;
    while (cin >> n >> m){
        vector<int> vec1(n);
        vector<int> vec2(m);
        for (int i=0; i<n; i++){
            cin >> vec1[i];
        }
        for (int i=0; i<m; i++){
            cin >> vec2[i];
        }
        TreeNode* root1 = new TreeNode;
        root1 = VecToTreenode(vec1, n, 0);
        TreeNode* root2 = new TreeNode;
        root2 = VecToTreenode(vec2, m, 0);
        bool ans = Solution().isSubtree(root1, root2);
        cout << ans << endl;
    }
}

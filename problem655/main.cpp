#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int w = pow(2, h) - 1;
        vector<vector<string>> ans(h, vector<string>(w, ""));
        print(root, 0, 0, w - 1, ans);
        return ans;
    }
private:
    // 计算树的高度
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    //打印树
    void print(TreeNode* root, int h, int l, int r, vector<vector<string>>& ans) {
        if (root == nullptr) return;
        int m = (l + r) / 2;
        ans[h][m] = to_string(root->val);
        print(root->left, h + 1, l, m - 1, ans);
        print(root->right, h + 1, m + 1, r, ans);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

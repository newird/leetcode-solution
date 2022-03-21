#include <iostream>
#include<unordered_set>

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
    bool findTarget(TreeNode *root, int k) {
        travel(root);
        for (auto c: set) {
            if (set.count(k - c) && k - c != c) return true;
        }
        return false;

    }

private:
    unordered_set<int> set;

    void travel(TreeNode *root) {
        if (!root) return;
        set.insert(root->val);
        if (root->left) travel(root->left);
        if (root->right) travel(root->right);
    }
};

int main() {
    Solution solution;

    return 0;
}

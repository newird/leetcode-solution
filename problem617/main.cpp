#include <iostream>


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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 ? root1 : root2;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

};

int main() {
    TreeNode *root1 = new TreeNode(1, new TreeNode(3, new TreeNode(5, nullptr, nullptr), nullptr),
                                   new TreeNode(2, nullptr, nullptr));
    TreeNode *root2 = new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4, nullptr, nullptr)),
                                   new TreeNode(3, nullptr, new TreeNode(7,
                                                                         nullptr,
                                                                         nullptr)));
    Solution solution;
    root1 = solution.mergeTrees(root1, root2);
    std::cout << root1->val << " " << root1->left->val;
    return 0;
}

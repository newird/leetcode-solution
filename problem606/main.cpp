#include <iostream>
#include<string>
#include <vector>

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
    string tree2str(TreeNode *root) {
        if (root == nullptr) return "";
        string ans;
        Preoder(root, ans);
        return ans;

    }

    void Preoder(TreeNode *root, string &s) {
        if (root == nullptr) s += "";
        else {
            s+= to_string(root->val);
            if (root->left || root->right) {
                s += "(";
                if (root->left) {
                    Preoder(root->left, s);
                }
                s += ")";

                if (root->right) {
                    s += "(";
                    Preoder(root->right, s);
                    s += ")";
                }
            }
        }
    }
};

int main() {
    TreeNode *right = new TreeNode(3, nullptr, nullptr);
    TreeNode *left = new TreeNode(2, nullptr, nullptr);
    TreeNode *root = new TreeNode(1, left, right);
    Solution s;
    cout << s.tree2str(root);
    return 0;
}

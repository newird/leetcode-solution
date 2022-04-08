#include <iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            ans.push_back(vector<int>());
            while (n--) {
                auto c = q.front();
                q.pop();
                ans.back().push_back(c->val);
                for(auto cc:c->children){
                    q.push(cc);
                }
            }

        }

        return ans;
    }
};

int main() {
    Node *root = new Node(1);
    Solution solution;
    auto ans = solution.levelOrder(root);
    int a = 1;
    return 0;
}

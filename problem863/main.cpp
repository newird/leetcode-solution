#include <iostream>
#include <vector>
#include<unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        build_graph(nullptr,root);
        vector<int> ans;
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        seen.insert(target);
        q.push(target);
        int k = 0;
        while(!q.empty() && k <= K ){
            int s = q.size();
            while(s --){
                TreeNode* node = q.front();q.pop();
                if(k == K) ans.push_back(node->val);
                for(auto c: g[node]){
                    if(seen.count(c)) continue;
                    q.push(c);
                    seen.insert(c);
                }
            }

            k++;
        }
        return ans;
    }

private:
    unordered_map<TreeNode*,vector<TreeNode*>> g;
    void build_graph(TreeNode* parent,TreeNode* child){
        if(parent){
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left) build_graph(child,child->left);
        if(child->right) build_graph(child,child->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

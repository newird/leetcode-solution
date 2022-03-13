#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        ans.clear();
        dis(root,target,K);
        return ans;
    }

private:
    vector<int> ans;
    int dis(TreeNode* root,TreeNode* target,int K){
        if(root == 0) return -1;
        if(root == target) {
            collect(root,K);
            return 0;
        }
        int l = dis(root->left,target,K);
        int r  = dis(root->right,target,K);
        if(l >= 0){
            if(l == K -1){
                ans.push_back(root->val);
            }
            collect(root->right,K- l -2);
            return l + 1;
        }
        if(r >= 0){
            if(r == K -1){
                ans.push_back(root->val);
            }
            collect(root->left,K - l -2);
            return r + 1;
        }
    }
    void collect(TreeNode* root,int d){
        if(root == nullptr || d < 0) return;
        if(d == 0) ans.push_back(root->val);
        collect(root->right, d-1);
        collect(root->left,d-1);
    }
};

int main(){
    return 0;
}
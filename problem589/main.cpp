#include <iostream>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> order;
    vector<int> preorder(Node* root) {
        if( root == NULL) return order;
        porder(root);
    }
    void porder(Node* p){
        order.push_back(p->val);
        for(auto child : p->children){
            porder(child);
        }
    }

};

int main() {
//   vector<int> root = {1,NULL,3,2,4,NULL,5,6};
}

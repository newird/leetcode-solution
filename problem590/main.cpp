#include <iostream>
#include<vector>
using  namespace  std;
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
    void Porder(Node * p){
        if(p){
            for(auto c:p->children){
                Porder(c);
            }
            order.push_back(p->val);
        }

    }
    vector<int> postorder(Node* root) {
        Porder(root);
        return order;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

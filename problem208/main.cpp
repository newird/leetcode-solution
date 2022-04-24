#include <iostream>
#include <utility>
#include<vector>
#include <memory>

using namespace std;
class Trie {
public:
    Trie() :root_(new TrieNode()){

    }

    void insert(string word) {
        for(auto c:word){
            TrieNode * p = root_.get();
            for(const auto c:word){
                if(!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
                p = p->children[c-'a'];
            }
            p->is_word = true;
        }
    }

    bool search(string word) {
        const TrieNode* p = find(word);
        return p&& p->is_word;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode{
        TrieNode():is_word(false),children(26, nullptr){}
        ~TrieNode(){
            for(auto *child:children){
                if(child) delete child;
            }
        }
        bool is_word;
        vector<TrieNode*> children;
    };
    const TrieNode *const find(const string word) const{
        const TrieNode* p =root_.get();
        for(const auto c: word){
            p = p->children[c-'a'];
            if(p == nullptr) break;
        }
        return p;
    }
    std::unique_ptr<TrieNode> root_;
};


int main(){
    Trie trie;
    cout<<trie.startsWith("a");
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

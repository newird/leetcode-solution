#include <iostream>
#include <string>
#include <unordered_set>
#include <list>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    AllOne() {
    }
    void inc(string key) {
        auto it = m_.find(key);
        if(it == m_.end()){
            if(l_.empty() || l_.front().value != 1){
                l_.push_front({1,{key}});
            }else{
                l_.front().keys.insert(key);
            }
            m_[key] = l_.begin();
            return;
        }

        auto lit = it->second;
        auto nit = next(lit);
        if(nit == l_.end() || nit->value != lit->value +1){
            nit = l_.insert(nit,{lit->value+1,{}});
        }
        nit->keys.insert(key);
        m_[key] = nit;
//        remove(lit,key);

        lit->keys.erase(key);
        if(lit->keys.empty()) l_.erase(lit);
    }

    void dec(string key) {
        auto it = m_.find(key);
        if(it == m_.end()) return ;

        auto lit = it->second;

        if(lit->value > 1){
            auto pit = prev(lit);
            if(lit == l_.begin() || pit->value != lit->value -1){
                pit = l_.insert(lit,{lit->value-1,{}});
            }
            pit->keys.insert(key);
            m_[key] = pit;
        }
        else{
            m_.erase(key);
        }
        lit->keys.erase(key);
        if(lit->keys.empty()) l_.erase(lit);

    }

    string getMaxKey() {
        return l_.empty()?"":*l_.back().keys.cbegin();
    }

    string getMinKey() {
        return l_.empty()?"":*l_.front().keys.cbegin();;
    }

private:
    struct Node{
        int value;
        unordered_set<string> keys;
    };
    list<Node> l_;
    unordered_map<string,list<Node>::iterator> m_;

};


int main() {
    AllOne allOne ;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("c");
    allOne.inc("c");
    allOne.inc("c");
    allOne.dec("b");
    allOne.dec("b");
    cout<< allOne.getMaxKey(); // 返回 "hello"
    cout<<allOne.getMinKey(); // 返回 "hello"
    allOne.dec("a");
    cout<<allOne.getMaxKey(); // 返回 "hello"
    cout<<allOne.getMinKey();

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

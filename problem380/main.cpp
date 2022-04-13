#include <iostream>
#include<unordered_set>
using namespace std;
class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if(set.count(val))
            return false;
        set.insert(val);
        return true;
    }

    bool remove(int val) {
        if(!set.count(val))
            return false;
        set.erase(val);
        return true;
    }

    int getRandom() {
        int i = rand()%set.size();
        auto it = set.begin();
        for(int j = 0;j<i;j++)
            it++;
        return *it;
    }

private:
    unordered_set<int> set;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

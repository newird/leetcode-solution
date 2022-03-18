#include <iostream>
#include <vector>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
//        if(account1<1 ||account1 > n || account2 <1 || account2> n ) return false;
//        if(balance[account2-1]  <money) return false;
//        balance[account2-1] -= money;
//        balance[account1-1] += money;
//        return true;
        if(withdraw(account1,money) && deposit(account2,money)) return true;
    }

    bool deposit(int account, long long money) {
        if( account > n) return  false;
        balance[account-1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if( account > n) return false;
        if(balance[account-1]< money) return false;
        balance[account-1] -= money;
        return true;
    }

private:
    vector<long long> balance;
    int n ;
};


int main() {
    vector<long long> balance = {10ll,100ll,20ll,50ll,30ll};
    Bank bank(balance);
    cout<<bank.withdraw(3,10)<<endl;
    cout<<bank.transfer(5,1,20)<<endl;
    cout<<bank.deposit(5,20)<<endl;
    cout<<bank.transfer(3,4,15)<<endl;
    cout<<bank.withdraw(10,50)<<endl;
    return 0;
}
//[null,false,false,true,false,true,false,true,true,false,true,true,true,false,false,true,true,true,true,true,false,true,false,true,false,true,true,false,false,false,true,true,true,false,true,false,false,false,false,false,true,true,false,false,false,false,true,false,false,false,false,false,false,true,true,false,true,true,true,true,true,true,true,false,false,false,true,true,true,false,true,false,true,true,true,false,true,false,true,false,true,true,true,false,true,false,true,true,false,false,true,true,true,true,false,false,false,true,false,true,false,false,true,true,true,true,false,false,false,true,true,false,false,true,true,false,false,true,false,true,true,false,false,true,false,false,true,false,true,true,true,false,false,true,true,false,false,true,true,true,false,false,false,false,true,true,false,false,false,true,false,false,true,true,true,true,true]
//[null,false,false,true,false,true,false,true,true,false,true,true,true,false,false,true,true,true,true,true,false,true,false,true,false,true,true,false,false,false,true,true,true,false,true,false,false,false,false,false,true,true,false,false,false,false,true,false,false,false,false,false,false,true,true,false,true,true,true,true,true,true,true,false,false,false,true,true,true,false,true,false,true,true,true,false,true,false,true,false,true,true,true,false,true,false,true,true,false,false,true,true,true,true,false,false,false,true,false,true,false,false,true,true,true,true,false,false,false,true,true,false,false,true,true,false,false,true,false,true,true,true,false,true,false,false,true,false,true,true,true,false,false,true,true,false,false,true,true,true,false,false,false,false,true,true,false,false,false,true,false,false,true,true,true,true,true]
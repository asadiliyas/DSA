class Bank {
public:
    // k = number of calls
    // n = number of bank accounts
    // TC = O(k)
    // SC= O(n)

    vector<long long> balanceArr;
    int n;

    Bank(vector<long long>& balance) {
        balanceArr = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {

        if (account1 > n || account2 > n) {
            return false;
        }

        if (balanceArr[account1 - 1] >= money) {
            balanceArr[account1 - 1] -= money;
            balanceArr[account2 - 1] += money;
            return true;
        } else {
            return false;
        }
    }

    bool deposit(int account, long long money) {

        if (account > n) {
            return false;
        }

        balanceArr[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {

        if (account > n) {
            return false;
        }

        if (balanceArr[account - 1] >= money) {
            balanceArr[account - 1] -= money;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

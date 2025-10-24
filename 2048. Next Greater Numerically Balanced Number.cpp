class Solution {
public:

    bool isBalanced(int n){
        vector<int>count(10,0);
        string strNum = to_string(n);
        for(int i = 0; i < strNum.size(); i++){
            int num = strNum[i] - '0';
            count[num]++;
        }

        for(int i = 0; i < 10; i++){
            if(count[i] > 0 && i != count[i]){
                return false;
            }
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        int ans = 1224444;
        for(int i = n + 1; i <= 1224444; i++){
            if(isBalanced(i) == true){
                ans = i;
                break;
            }
        }

        return ans;
    }
};

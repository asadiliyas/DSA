class Solution {
public:
    int totalMoney(int n) {

        // TC = O(n)
        // SC = O(1)

        int ans = 0;
        int prevMondayMoney = 0;
        int currMon;
        for(int i = 1; i <= n ; i++){
            if(i % 7 == 1){
                prevMondayMoney++;
                currMon = prevMondayMoney;
                ans += currMon;
            }

            else{
                currMon++;
                ans += currMon;
            }
        }

        return ans;
    }
};

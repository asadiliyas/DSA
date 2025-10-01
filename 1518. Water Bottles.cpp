class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filledBottles = numBottles;
        int ans = filledBottles;
        int emptyBottles = filledBottles;
        while (emptyBottles >= numExchange) {
            filledBottles = emptyBottles / numExchange;
            ans += filledBottles;
            emptyBottles = filledBottles + emptyBottles % numExchange;
        }

        return ans;
    }
};

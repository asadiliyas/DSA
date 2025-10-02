class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange){
            emptyBottles = emptyBottles - numExchange + 1;
            ans++;
            numExchange++;
        }

        return ans;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        vector<int> basketPresent(n, 1);

        int result = 0;

        for (int i = 0; i < n; i++) {
            
            bool fruitTaken = false;
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j] && basketPresent[j] == 1) {
                    fruitTaken = true;
                    basketPresent[j] = 0;
                    break;
                }
            }

            if (fruitTaken == false) {
                result++;
            }
            
        }

        return result;
    }
};

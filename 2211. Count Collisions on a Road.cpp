class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int countRight = 0;
        int countStationary = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'L') {
                if (countRight > 0) {
                    ans += countRight + 1;
                    countRight = 0;
                } else if (countStationary > 0 || ans>0) {
                    ans++;
                }
            } else if (directions[i] == 'R') {
                countRight++;
            } else {
                if (countRight > 0) {
                    ans += countRight;
                    countRight = 0;
                }
                countStationary++;
            }
        }

        return ans;
    }
};

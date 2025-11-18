class Solution {
public:

    // TC = O(N)
    // SC = O(1)

    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n) {
            if (bits[i] == 1) {
                i += 2;
                continue;
            }
            if (i == n - 1 && bits[i] == 0) {
                return true;
            }
            i++;
        }
        return false;
    }
};

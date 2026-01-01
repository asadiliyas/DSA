class Solution {
public:

    // TC = O(n)
    // SC = O(1)

    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int i = digits.size() - 1;
        int carry = 1;
        vector<int> ans = digits;
        while (carry && i >= 0) {
            if (ans[i] == 9) {
                ans[i] = 0;
            } else {
                ans[i] = ans[i] + 1;
                carry = 0;
            }
            i--;
        }

        if (carry == 1) {
            ans.insert(ans.begin(), 1);
        }

        return ans;
    }
};

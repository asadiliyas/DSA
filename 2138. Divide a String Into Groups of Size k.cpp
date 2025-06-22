class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        // TC=O(N)
        // SC=O(k)
        int n = s.length();
        string temp = "";
        vector<string> result;
        for (int i = 0; i < n; i += k) {
            int end = i + k - 1 >= n ? n - 1 : i + k - 1; // end index
            temp = s.substr(i, end - i + 1);
            if (temp.size() != k) {
                int remainCount = k - temp.size();
                temp += string(remainCount, fill);
            }
            result.push_back(temp);
        }
        return result;
    }
};

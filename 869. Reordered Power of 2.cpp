class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<string, bool>mp;
        long long num = 1;
        string temp;

        while(num < INT_MAX){
            temp = to_string(num);
            sort(temp.begin(), temp.end());
            mp[temp] = true;
            num *= 2;
        }

        string numStr = to_string(n);
        
        sort(numStr.begin(), numStr.end());

        return mp[numStr] == true;
    }
};

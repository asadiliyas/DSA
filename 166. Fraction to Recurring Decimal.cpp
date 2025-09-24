class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if(numerator == 0){
            return "0";
        }

        string ans = "";

        if((long long)numerator * (long long)denominator < 0){
            ans += "-";
        }

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        ans += to_string(absNumerator/absDenominator);

        long long remain = absNumerator % absDenominator;

        if(remain == 0){
            return ans;
        }

        ans += ".";

        unordered_map<int,int>remain_idx_mp;

        while(remain != 0){

            if(remain_idx_mp.count(remain)){
                ans.insert(remain_idx_mp[remain], "(");
                ans += ")";
                break;
            }

            remain_idx_mp[remain] = ans.length();

            remain *= 10;

            ans += to_string(remain/absDenominator);
            remain = remain%absDenominator;

        }

            return ans;

    }
};

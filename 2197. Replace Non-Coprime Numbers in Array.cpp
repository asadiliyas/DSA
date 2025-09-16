class Solution {
public:

    vector<int> replaceNonCoprimes(vector<int>& nums) {

        int n = nums.size();
        vector<int> result;
        stack<int>left;
        stack<int>right;

        for (int& num : nums) {
            left.push(num);
        }


        while(!left.empty()) {

            //checks left adjacent
            while(!right.empty() && gcd(left.top(), right.top()) > 1){
                int HCF = gcd(left.top(), right.top());
                long long LCM = right.top() / HCF;
                LCM *= left.top();
                left.pop();
                right.pop();
                left.push(LCM);
            }

            //checks left adjacent
            int first = left.top();
            left.pop();

            if(left.empty()){
                right.push(first);
                break;
            }

            int second = left.top();
            left.pop();

            if(gcd(first, second) > 1){
                int HCF = gcd(first, second);
                long long LCM = first / HCF;
                LCM *= second;
                left.push(LCM);
            }

            else{
                right.push(first);
                left.push(second);
            }

        }


        while (!right.empty()) {
            int num = right.top();
            right.pop();
            if (num > 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};

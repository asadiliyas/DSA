class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        //total digits in half
        int d=(n+1)/2;
        int start=pow(10,d-1);
        int end=pow(10,d)-1;
        unordered_set<string>st;

        //precompute factorial
        vector<long long>factorial(11,1);
        for(int i=1;i<11;i++){
            factorial[i]=i*factorial[i-1];
        }

        //make n digit palindrome
        for(int num=start;num<=end;num++){
            string s=to_string(num);
            string full="";
            if(n%2==0){
                string left=s;
                string right=s;
                reverse(right.begin(),right.end());
                full=left+right;
            }
            else{
                string left=s;
                string right=left.substr(0,d-1);
                reverse(right.begin(),right.end());
                full=left+right;
            }

            long long number = stoll(full);
            if(number%k==0){
                sort(full.begin(),full.end());
                st.insert(full);
            }
        }

        //count permutaion
        long long ans=0;
        for(const string &s:st){
            vector<int>count(10,0);
            for(int i=0;i<s.size();i++){
                count[s[i]-'0']++;
            }

            int countZero=count[0];
            int countNonZero=n-countZero;

            long long permutations=countNonZero*factorial[n-1];

            for(int i=0;i<10;i++){
                permutations/=factorial[count[i]];
            }

            ans+=permutations;
        }
        return ans;
    }
};

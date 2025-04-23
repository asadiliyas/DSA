class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            int sum=0;
            for(int j=0;j<s.size();j++){
                sum+=s[j]-'0';
            }
            mp[sum]++;
        }

        int maxCount=0;
        for(auto& it:mp){
            maxCount=max(maxCount,it.second);
        }

        for(auto& it:mp){
            if(it.second==maxCount)
            ans++;
        }
        return ans;
    }
};

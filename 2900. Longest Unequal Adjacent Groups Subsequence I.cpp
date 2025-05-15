class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
       vector<string>result;
       int n=words.size();
       int currPolarity=-1;
       for(int i=0;i<n;i++){
            if(currPolarity!=groups[i]){
                result.push_back(words[i]);
                currPolarity=groups[i];
            }
       } 
       return result;
    }
};

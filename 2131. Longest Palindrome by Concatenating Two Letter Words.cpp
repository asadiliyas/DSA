class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int result = 0;
        int centreLength=0;
        for (string& word : words) {
            mp[word]++;
        }

        for (auto it = mp.begin(); it != mp.end();) {
            string word = it->first;
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            if (word != revWord) {
                if (mp.count(revWord)) {
                    result += min(mp[word], mp[revWord]) * 4;
                    mp.erase(revWord);
                }
                it = mp.erase(it);

            } else {
                if(mp[word]%2==0){
                    result+=mp[word]*2;
                }
                else{
                    result+=(mp[word]-1)*2;
                    centreLength=2;
                }
                it++;
            }
        }
        return result + centreLength;
    }
};

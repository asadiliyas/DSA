class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>result;
        for(int i=0;i<n;i++){
            string word=words[i];
            for(char &c:word){
                if(c==x){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

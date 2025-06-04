class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
        return word;
        int n = word.size();
        int maxLength = n - numFriends + 1;
        string result;
        for (int i = 0; i < n; i++) {
            int canTake = min(maxLength, n - i);
            result = max(result, word.substr(i, canTake));
        }
        return result;
    }
};

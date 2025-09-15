class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<int> brokenLetterArr(26, 0);

        for (char ch : brokenLetters) {
            if (ch != ' ') {
                brokenLetterArr[ch - 'a'] = 1;
            }
        }

        int result = 0;

        int brokenFound = 0;

        text.push_back(' ');

        for (char ch : text) {

            if (ch != ' ' && brokenLetterArr[ch - 'a'] == 1) {
                brokenFound++;
            }

            if (ch == ' ') {
                if (brokenFound == 0) {
                    result++;
                }
                brokenFound = 0;
            }
        }

        return result;
    }
};

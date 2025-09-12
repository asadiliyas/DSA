class Solution {
public:
    bool doesAliceWin(string s) {
        int totalVowel = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                totalVowel++;
            }
        }

        if(totalVowel == 0){
            return false;
        }


        return true;


    }
};

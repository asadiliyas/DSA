class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int countAndSay=1;
        while (countAndSay != n) {
            int count = 1;
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                if (i == s.size() - 1 || s[i] != s[i + 1]) {
                    temp += count + '0';
                    temp += s[i];
                    count = 1;

                } else {
                    count++;
                }
            }
            s = temp;
            countAndSay++;
        }
        return s;
    }
};

class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 1;
        char prevChar = '#';
        string ans = "";
        int currMaxNum = -1;
       for(char &c : num){
            if(c == prevChar){
                count++;
                if(count == 3 && (c - '0') > currMaxNum){
                    currMaxNum = c - '0';
                    ans = string (3,c);
                }
            }
            else{
                count = 1;
            }

            prevChar = c;
       } 

       return ans;
    }
};

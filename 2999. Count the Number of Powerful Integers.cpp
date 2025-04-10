class Solution {
public:

    long long solve(string& str,string &inputSuf,int& limit){

        if(str.length()<inputSuf.length())
        return 0;

        long long count = 0;
        string trailStr = str.substr(str.length()-inputSuf.length());
        int remL = str.length()-inputSuf.length();
        for(int i=0;i<remL;i++){
            int digit = str[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1,remL-i-1);
            }
            else{
                count+=pow(limit+1,remL-i);
                return count;
            }
        }

        if(trailStr>=inputSuf)
        count++;

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suf) {
        string startStr = to_string(start-1);
        string endStr = to_string(finish);
        return solve(endStr,suf,limit)-solve(startStr,suf,limit);
    }
};

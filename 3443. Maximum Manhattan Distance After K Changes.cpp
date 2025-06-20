class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int N = 0, W = 0, S = 0, E = 0;
        int result=0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'N') {
                N++;
            } else if (c == 'W') {
                W++;
            } else if (c == 'S') {
                S++;
            } else {
                E++;
            }

            int currDist=abs(N-S)+abs(E-W);
            int totalSteps=i+1;
            int maxDist=min(totalSteps,currDist+2*k);//1 unit k can increase dist by 2
            result=max(result,maxDist);
        }
        return result;
    }
};

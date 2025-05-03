class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int>count(7,0);
        int maxiOccEle=0;
        int maxEle=-1;

        for(int i=0;i<n;i++){
            count[tops[i]]++;
            count[bottoms[i]]++;
        }

        for(int i=1;i<=6;i++){
            if(count[i]>=n){
                maxEle=i;
            }
        }

        if(maxEle==-1)
        return -1;

        int countTop=0;
        int countBottom=0;

        for(int i=0;i<n;i++){
            if(tops[i]!=maxEle && bottoms[i]!=maxEle)
            return -1;

            if(tops[i]==maxEle){
                countTop++;
            }

            if(bottoms[i]==maxEle){
                countBottom++;
            }
        }

        return n-max(countTop,countBottom);

    }
};

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int n=dominoes.size();

        vector<vector<int>>count(9,vector<int>(9,0));

        for(int i=0;i<n;i++){
            int row=min(dominoes[i][0],dominoes[i][1]);
            int col=max(dominoes[i][0],dominoes[i][1]);
            count[row-1][col-1]++;
        }

        int result=0;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(count[i][j]>1){
                    result+=(count[i][j]*(count[i][j]-1))/2;
                }
            }
        }

        return result;
    }
};

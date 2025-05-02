class Solution {
public:
    string pushDominoes(string dominoes) {
      int n=dominoes.size();
      vector<int>fall(n,0);
      //Right traversing
      int power=n;
      for(int i=0;i<n;i++){
        if(dominoes[i]=='R'){
            fall[i]+=n;
            power=n-1;
        }
        else if(dominoes[i]=='L'){
            power=n;
        }
        else{
            if(power<n){
                fall[i]+=power;
                power--;
            }
        }
      }
      //left traversing
      power=n;
      for(int i=n-1;i>=0;i--){
        if(dominoes[i]=='L'){
            fall[i]-=n;
            power=n-1;
        }
        else if(dominoes[i]=='R'){
            power=n;
        }
        else{
            if(power<n){
                fall[i]-=power;
                power--;
            }
        }
      }

        for(int i=0;i<n;i++){
            if(fall[i]>0){
                dominoes[i]='R';
            }
            else if(fall[i]<0){
                dominoes[i]='L';
            }
            else{
                dominoes[i]='.';
            }
        }

        return dominoes;

    }
};

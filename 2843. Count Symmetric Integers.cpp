class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int num=low;num<=high;num++){
            if(num>=10&&num<=99&&num%11==0)
            ans++;

            else if(num>=1000&&num<=9999){
                int currNum=num;
                int onePlace=num%10;
                num/=10;
                int tenPlace=num%10;
                num/=10;
                int hundPlace=num%10;
                num/=10;
                int thouPlace=num%10;

                if(onePlace+tenPlace==hundPlace+thouPlace)
                ans++;

                num=currNum;
            }
        }
        return ans;
    }
};

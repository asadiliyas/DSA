class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid){
        multiset<int>st(workers.begin(),workers.begin()+mid);//best mid workers
        for(int i=mid-1;i>=0;i--){
            int reqTask=tasks[i];
            auto it=prev(st.end());
            if(*it>=reqTask){
                st.erase(it);
            }
            else if(pills==0)
            return false;

            else{
                auto weakestWorkerit=st.lower_bound(reqTask-strength);
                if(weakestWorkerit==st.end())
                return false;

                st.erase(weakestWorkerit);
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        int maxAns=min(n,m);
        int result=0;
        sort(tasks.begin(),tasks.end());//weakest task
        sort(workers.begin(),workers.end(),greater<int>());//strongest workers
        int start=0,end=maxAns;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(tasks,workers,pills,strength,mid)){
                result=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return result;
    }
};

class Solution {
public:
    // TC = n*logn(loop*binarySearch(upperBound))
    // SC = n

    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // dummy value 1 for drying if no lake to dry
        unordered_map<int, int> mp_lake_lastIndex;
        set<int> st_zeroIndex;

        for (int i = 0; i < n; i++) {

            int lake = rains[i];

            // we have to dry lake
            if (lake == 0) {
                st_zeroIndex.insert(i);
            }
            // Rain happening
            else {
                // lake already filled
                if (mp_lake_lastIndex.find(lake) != mp_lake_lastIndex.end()) {
                    int lastIndex = mp_lake_lastIndex[lake];
                    auto it = st_zeroIndex.upper_bound(lastIndex);
                    if (it == st_zeroIndex.end()) {
                        return {};
                    } else {
                        int zeroIndexUsed = *it;
                        st_zeroIndex.erase(it);
                        ans[zeroIndexUsed] = lake;
                    }
                }
                ans[i] = -1;
                mp_lake_lastIndex[lake] = i;
            }
        }

        return ans;
    }
};

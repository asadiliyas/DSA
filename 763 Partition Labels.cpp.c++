class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> result;
            unordered_map<char, int> count;
            for (auto& c : s) {
                count[c]++;
            }
            set<char> st;
            unordered_map<char, int> count2;
            int size=0;
            for (auto& c : s) {
                st.insert(c);
                count2[c]++;
                size++;
                bool flag=true;
                for (auto& ch : st) {
                    if (count2[ch] != count[ch]) {
                        flag = false;
                        break;
                    }
                }
                if(flag==true){
                    result.push_back(size);
                    size=0;
                    st.clear();
                }
            }
            return result;
        }
    };
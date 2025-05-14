#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Create the transformation matrix M where M[i][j] is the number of times i contributes to j in one step
        vector<vector<long long>> mat(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            int k = nums[i];
            for (int j = 1; j <= k; ++j) {
                int next_char = (i + j) % 26;
                mat[i][next_char]++;
            }
        }

        // Compute mat^t using matrix exponentiation
        vector<vector<long long>> resultMat = matrixExpo(mat, t);

        // Multiply the initial frequency vector with the resultMat
        vector<long long> newFreq(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                newFreq[j] = (newFreq[j] + freq[i] * resultMat[i][j]) % M;
            }
        }

        // Sum all frequencies
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + newFreq[i]) % M;
        }
        return ans;
    }

private:
    vector<vector<long long>> multiplyMatrices(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
        int n = a.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % M;
                }
            }
        }
        return res;
    }

    vector<vector<long long>> matrixExpo(vector<vector<long long>>& mat, int power) {
        int n = mat.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        // Initialize result as identity matrix
        for (int i = 0; i < n; ++i) {
            result[i][i] = 1;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                result = multiplyMatrices(result, mat);
            }
            mat = multiplyMatrices(mat, mat);
            power /= 2;
        }
        return result;
    }
};

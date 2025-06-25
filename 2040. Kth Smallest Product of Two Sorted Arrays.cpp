class Solution {
public:
    long long countProductLessThan(vector<int>& nums1, vector<int>& nums2,
                                   long long productTaken) {
        // TC = O(log(maxP-minP)*n*logm)
        // SC = O(1)
        long long count = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                int l = 0, r = nums2.size() - 1;
                int m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1ll * nums1[i] * nums2[mid];
                    if (product <= productTaken) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += m + 1;
            }

            else {
                int l = 0, r = nums2.size() - 1;
                int m = nums2.size();
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];
                    if (product <= productTaken) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += nums2.size() - m;
            }
        }

        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long result;    // kthSmallest
        long long l = -1e10; // min product
        long long r = 1e10;  // max product

            while (l <= r) {
                long long midProduct =
                    l + (r - l) / 2; // assume this will be the ans
                long long countProduct = countProductLessThan(
                    nums1, nums2, midProduct); // countProduct<=k
                // probable answer
                if (countProduct >= k) {
                    result = midProduct;
                    r = midProduct - 1;
                } else {
                    l = midProduct + 1;
                }
            }


        return result;
    }
};

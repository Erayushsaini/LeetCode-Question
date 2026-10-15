
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Always perform binary search on the smaller array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int N = m + n;
        int s = (N + 1) / 2;

        int str = 0;
        int end = m;

        while (str <= end) {
            int mid1 = str + (end - str) / 2;
            int mid2 = s - mid1;

            int l1, l2, r1, r2;

            // Left boundary of nums1
            if (mid1 == 0)
                l1 = INT_MIN;
            else
                l1 = nums1[mid1 - 1];

            // Left boundary of nums2
            if (mid2 == 0)
                l2 = INT_MIN;
            else
                l2 = nums2[mid2 - 1];

            // Right boundary of nums1
            if (mid1 == m)
                r1 = INT_MAX;
            else
                r1 = nums1[mid1];

            // Right boundary of nums2
            if (mid2 == n)
                r2 = INT_MAX;
            else
                r2 = nums2[mid2];

            // Valid partition
            if (l1 <= r2 && l2 <= r1) {
                if (N % 2 == 0) {
                    return (max(l1, l2) + (double)min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            }
            // Move partition left in nums1
            else if (l1 > r2) {
                end = mid1 - 1;
            }
            // Move partition right in nums1
            else {
                str = mid1 + 1;
            }
        }

        return 0.0;
    }
};
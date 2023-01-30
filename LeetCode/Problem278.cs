class Solution {
    public int firstBadVersion(int n) {
        long left = 1, right = n;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (isBadVersion(mid)) right = mid - 1;
            else left = mid + 1;
        } 
        return left;
    }
};
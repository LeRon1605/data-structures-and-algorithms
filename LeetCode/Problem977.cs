public class Solution {
    public int[] SortedSquares(int[] nums) {
        int left = 0, right = nums.Length - 1;
        int []result = new int[nums.Length];
        int current = right;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result[current--] = nums[right] * nums[right];
                right -= 1;
            } else {
                result[current--] = nums[left] * nums[left];
                left += 1;
            }
        }
        return result;
    }
}
public class Solution {
    public void Rotate(int[][] matrix) {
        for (int i = 0;i < matrix.Length;i++) {
            for (int j = 0;j < i;j++) {
                int temp = matrix[i][j];               
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0;i < matrix.Length / 2;i++) {
            for (int j = 0;j < matrix[i].Length;j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][matrix.Length - 1 - i];
                matrix[j][matrix.Length - 1 - i] = temp;
            }
        }
    }
}
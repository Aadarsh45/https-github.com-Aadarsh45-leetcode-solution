public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] memo = new int[m + 1][n + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return lcsMemo(text1, text2, m, n, memo);
    }

    private int lcsMemo(String text1, String text2, int m, int n, int[][] memo) {
        if (m == 0 || n == 0) {
            return 0;
        }

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        if (text1.charAt(m - 1) == text2.charAt(n - 1)) {
            memo[m][n] = 1 + lcsMemo(text1, text2, m - 1, n - 1, memo);
        } else {
            memo[m][n] = Math.max(lcsMemo(text1, text2, m - 1, n, memo), lcsMemo(text1, text2, m, n - 1, memo));
        }

        return memo[m][n];
    }
}
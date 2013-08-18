import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] prevSum;
    static int[] inp;
    static int[][] dp;

    static int getValue(int i, int j) {
        return prevSum[j] - prevSum[i] + inp[i];
    }

    static int solveBest(int i, int j) {
        if (i > j)
            return 0;
        else if (dp[i][j] != Integer.MIN_VALUE)
            return dp[i][j];
        else {
            int max = Integer.MIN_VALUE;
            for (int k = i; k <= j; k++) {
                max = Math.max(max, getValue(i, k) - solveBest(k + 1, j));
            }

            for (int k = j; k >= i; k--) {
                max = Math.max(max, getValue(k, j) - solveBest(i, k - 1));
            }
            return dp[i][j] = max;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        StringBuilder out = new StringBuilder();
        int n;
        while ((n = sc.nextInt()) != 0) {
            prevSum = new int[n];
            inp = new int[n];
            inp[0] = prevSum[0] = sc.nextInt();

            for (int i = 1; i < prevSum.length; i++) {
                inp[i] = sc.nextInt();
                prevSum[i] = prevSum[i - 1] + inp[i];
            }

            dp = new int[n][n];
            for (int i = 0; i < dp.length; i++)
                Arrays.fill(dp[i], Integer.MIN_VALUE);

            out.append(solveBest(0, n - 1) + "\n");

        }
        System.out.print(out);
    }
}
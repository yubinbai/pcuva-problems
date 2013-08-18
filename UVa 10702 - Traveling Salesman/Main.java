import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int[][] G;
            int c = in.nextInt();
            int s = in.nextInt();
            int nDest = in.nextInt();
            int intermidate = in.nextInt();
            if (c == 0 && s == 0 && nDest == 0 && intermidate == 0)
                break;
            G = new int[c + 1][c + 1];
            for (int i = 1; i < G.length; i++)
                for (int j = 1; j < G.length; j++)
                    G[i][j] = in.nextInt();
            int[] end = new int[nDest];
            for (int i = 0; i < end.length; i++)
                end[i] = in.nextInt();
            int[][] dp = new int[c + 1][intermidate + 1];
            for (int i = 0; i < dp.length; i++)
                Arrays.fill(dp[i], -(1 << 25));
            for (int i = 0; i < end.length; i++)
                dp[end[i]][intermidate] = 0;
            for (int i = intermidate - 1; i >= 0; i--)
                for (int j = 1; j < G.length; j++)
                    for (int k = 1; k < G.length; k++)
                        dp[j][i] = Math.max(dp[j][i], G[j][k] + dp[k][i + 1]);
            System.out.println(dp[s][0]);
        }
    }
}
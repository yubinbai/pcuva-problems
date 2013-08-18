import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, t, m;
    static int [] inp;
    static int [][][] dp;
    static int solve(int i, int m, int reminder) {
        StringBuilder s ;
        if (i >= n)
            return 0;
        else if (dp[i][m][reminder] != -1)
            return dp [i][m][reminder];
        else {
            if (reminder < inp[i]) {
                if (m > 0)
                    return dp [i][m][reminder] = Math.max(solve(i + 1, m, reminder), 1 + solve(i + 1, m - 1, t - inp[i]));
                else
                    return dp [i][m][reminder] = solve(i + 1, m, reminder);
            } else {
                if (m > 0)
                    return dp [i][m][reminder] = Math.max(1 + solve(i + 1, m, reminder - inp[i]),
                                                          Math.max(solve(i + 1, m, reminder), 1 + solve(i + 1, m - 1, t - inp[i])));
                else
                    return dp [i][m][reminder] = Math.max(1 + solve(i + 1, m, reminder - inp[i]), solve(i + 1, m, reminder));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        String [] sp;
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            br.readLine();
            sp = br.readLine().split(" ");
            n = Integer.parseInt(sp[0]);
            t = Integer.parseInt(sp[1]);
            m = Integer.parseInt(sp[2]);
            inp = new int [n];
            dp = new int [n][m][t + 1];
            sp = br.readLine().split(", ");
            for (int j = 0; j < n; j++) {
                inp[j] = Integer.parseInt(sp[j]);
                for (int k = 0; k < m; k++) {
                    Arrays.fill(dp[j][k], -1);
                }
            }
            out.append(solve(0, m - 1, t) + "\n");
            if (i < T - 1)
                out.append("\n");
        }
        System.out.print(out);
    }
}
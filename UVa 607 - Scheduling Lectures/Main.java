import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int l, c;
    static int[] topics = new int[1002];
    static int[] dp = new int[1002];
    static int[] dp2 = new int[1002];

    public static int w(int t) {
        return (t == 0) ? 0 : (t <= 10) ? -c : ((t - 10) * (t - 10));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = 1;
        while (true) {

            int n = in.nextInt();
            if (n == 0)
                break;
            if (tc != 1)
                System.out.println();
            l = in.nextInt();
            c = in.nextInt();
            for (int i = 0; i < n; i++)
                topics[i] = in.nextInt();
            dp[n] = dp2[n] = 0;
            for (int i = n - 1; i >= 0; i--) {
                dp[i] = 1 + dp[i + 1];
                int tleft = l - topics[i];
                dp2[i] = w(tleft) + dp2[i + 1];
                for (int j = i + 1; j < n && tleft >= topics[j]; j++) {
                    tleft -= topics[j];
                    if (dp[j + 1] + 1 < dp[i]
                            || (dp[j + 1] + 1 == dp[i] && dp2[j + 1] + w(tleft) < dp2[i])) {
                        dp[i] = 1 + dp[j + 1];
                        dp2[i] = dp2[j + 1] + w(tleft);
                    }
                }

            }
            System.out.printf("Case %d:\n", tc++);
            System.out.printf("Minimum number of lectures: %d\n", dp[0]);
            System.out.printf("Total dissatisfaction index: %d\n", dp2[0]);
        }
    }
}
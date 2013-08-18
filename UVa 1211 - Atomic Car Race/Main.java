import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while (true) {
            int N = scan.nextInt();
            if (N == 0)
                break;
            int[] array = new int[N];
            for (int i = 0; i < N; i++) {
                array[i] = scan.nextInt();
            }
            double b = scan.nextDouble();
            int r = scan.nextInt();
            double v = scan.nextDouble();
            double e = scan.nextDouble();
            double f = scan.nextDouble();
            
            double[] dp = new double[N + 1];
            for (int i = 0; i <= N; i++) {
                dp[i] = Double.MAX_VALUE;
            }
            dp[0] = 0.0;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j <= N; j++) {
                    int dist;
                    if (i == 0)
                        dist = array[j - 1];
                    else
                        dist = array[j - 1] - array[i - 1];
                    double time = 0.0;
                    for (int x = 0; x < dist; x++) {
                        if (x >= r)
                            time += 1.0 / (v - e * (x - r));
                        else
                            time += 1.0 / (v - f * (r - x));
                    }
                    if (i == 0)
                        dp[j] = (dp[j] > dp[i] + time) ?  dp[i] + time : dp[j];
                    else
                        dp[j] = (dp[j] > dp[i] + time + b) ? dp[i] + time + b : dp[j];
                }
            }
            System.out.format("%.6f\n", dp[N]);
        }

    }
}
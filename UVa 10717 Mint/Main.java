import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] coins = new int[51];
        int nC = in.nextInt();
        int nT = in.nextInt();
        while (nC != 0 || nT != 0) {
            for (int i = 0; i < nC; i++)
                coins[i] = in.nextInt();
            for (int i = 0; i < nT; i++) {
                int t = in.nextInt();
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                for (int a = 0; a < nC; a++)
                    for (int b = a + 1; b < nC; b++)
                        for (int c = b + 1; c < nC; c++)
                            for (int d = c + 1; d < nC; d++) {
                                int len = lcm(lcm(coins[a], coins[b]),
                                              lcm(coins[c], coins[d]));
                                max = Math.max(max, (t / len) * len);
                                min = Math.min(min,
                                               (t / len + ((t % len != 0) ? 1 : 0))
                                               * len);

                            }
                System.out.println(max + " " + min);
            }
            nC = in.nextInt();
            nT = in.nextInt();
        }
    }
}
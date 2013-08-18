import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    static final int N = 160, D = 160;
    static int n, d;
    static BigInteger c[][] = new BigInteger[N][D];
    public static void main(String[] arg) {
        init();
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextInt()) {
            n = cin.nextInt();
            d = cin.nextInt();
            if (0 != n % 2)
                System.out.println("0");
            else
                System.out.println(c[n / 2][d].subtract(c[n / 2][d - 1]));
        }
    }
    static void init() {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < D; ++j)
                c[i][j] = new BigInteger("0");
        for (int j = 0; j < D; ++j)
            c[0][j] = new BigInteger("1");
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < D; ++j)
                for (int k = 0; k < i; ++k)
                    c[i][j] = c[i][j].add(c[k][j - 1].multiply(c[i - k - 1][j]));
    }
}
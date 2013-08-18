import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger[] f = new BigInteger[10010];
        f[0] = new BigInteger("0");
        int k = 1, cnt = 0;
        BigInteger d = new BigInteger("1");
        for (int i = 1; i <= 10000; i ++) {
            f[i] = f[i - 1].add(d);
            cnt ++;
            if (cnt == k) {
                cnt = 0;
                k ++;
                d = d.multiply(BigInteger.valueOf(2));
            }
        }
        while (cin.hasNext()) {
            int n = cin.nextInt();
            System.out.println(f[n]);
        }
    }
}
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        BigInteger[] dp = new BigInteger[10005];
        dp[0] = new BigInteger("0");
        BigInteger num = new BigInteger("1");
        int k = 0, flag = 1;
        for (int i = 1; i < 10001; i++) {
            dp[i] = new BigInteger("0");
            if (k == flag)  {
                k = 0;
                flag++;
                num = num.multiply(BigInteger.valueOf(2));
            }
            k++;
            dp[i] = dp[i - 1].add(num);
        }
        System.out.println(dp[10000]);
    }
}

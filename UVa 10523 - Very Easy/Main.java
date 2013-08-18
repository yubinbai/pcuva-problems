import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BigInteger ZERO = new BigInteger("0");
        BigInteger ONE = new BigInteger("1");
        BigInteger A = new BigInteger("0");
        int N = 0;
        Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            N = in.nextInt();
            A = in.nextBigInteger();
            BigInteger sum = ZERO;
            int i = 0;
            BigInteger j = ONE;
            for (i = 1, j = ONE; i <= N; i++, j = j.add(ONE)) {
                BigInteger val = A.pow(i);
                val = val.multiply(j);
                sum = sum.add(val);
            }
            System.out.println(sum);
        }
    }
}
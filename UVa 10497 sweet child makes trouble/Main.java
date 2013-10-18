import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        StringBuffer sb = new StringBuffer("");
        BigInteger fib[] = new BigInteger[801];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ZERO;
        fib[2] = BigInteger.ONE;
        fib[3] = BigInteger.valueOf(2);
        for (int i = 4; i < 801; i++) {
            fib[i] = (fib[i - 2].add(fib[i - 1])).multiply(BigInteger.valueOf(i - 1));
        }
        while (true) {
            int m = sc.nextInt();
            if (m == -1)
                break;
            sb.append(fib[m]).append("\n");
        }
        System.out.print(sb);
    }

}
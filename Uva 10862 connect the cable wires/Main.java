import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
    public static void main (String [] args) throws NumberFormatException, IOException {
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        BigInteger [] fib = new BigInteger[4001];
        fib[1] = new BigInteger("1");
        fib[2] = new BigInteger("1");
        for (int i = 3; i < 4001; i++)
            fib[i] = fib[i - 1].add(fib[i - 2]);
        while (true) {
            int n = Integer.parseInt(buf.readLine());
            if (n == 0)
                break;
            System.out.println(fib[2 * n]);
        }
    }
}
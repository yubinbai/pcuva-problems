import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i < n + 1; i++) {
            int x = Integer.parseInt(br.readLine());
            sb.append("Case #").append(i).append(": ");
            BigInteger bg = BigInteger.valueOf(x).mod(BigInteger.valueOf(1000000007));
            bg = bg.multiply(BigInteger.valueOf(2).modPow(BigInteger.valueOf(x - 1), BigInteger.valueOf(1000000007))).mod(BigInteger.valueOf(1000000007));
            sb.append(bg).append("\n");
        }
        System.out.print(sb);
    }
}
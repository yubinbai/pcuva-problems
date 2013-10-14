import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BigInteger sum = BigInteger.ZERO;
        BigInteger []x = new BigInteger[50 * 1000 + 1];
        for (int i = 1; i < 50 * 1000 + 1; i++) {
            sum = sum.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(i)).multiply(BigInteger.valueOf(i)));
            x[i] = sum;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        String m = "";
        while ((m = br.readLine()) != null) {
            int num = Integer.parseInt(m);
            sb.append(x[num]).append("\n");
        }
        System.out.print(sb);
    }
}
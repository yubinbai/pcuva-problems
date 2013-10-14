import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        String m = "";
        BigInteger[] arr = new BigInteger[1001];
        for (int i = 0; i < 1001; i++) {
            arr[i] = BigInteger.ZERO;
        }
        for (int i = 0; i < 1001; i++) {
            fact(i, arr);
        }
        int sum[] = new int[1001];
        for (int i = 0; i < 1001; i++) {
            String temp = arr[i].toString();
            for (int j = 0; j < temp.length(); j++) {
                sum[i] += temp.charAt(j) - '0';
            }
        }
        while ((m = br.readLine()) != null) {
            int x = Integer.parseInt(m);
            sb.append(sum[x]).append("\n");
        }
        System.out.print(sb);
    }

    static BigInteger fact(int x, BigInteger[] arr) {
        if (x == 1 || x == 0) {
            return BigInteger.ONE;
        }
        if (arr[x] != BigInteger.ZERO) {
            return arr[x];
        }
        arr[x] = BigInteger.valueOf(x).multiply(fact(x - 1, arr));
        return arr[x];
    }
}
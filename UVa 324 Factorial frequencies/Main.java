import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        BigInteger[] fact = new BigInteger[367];
        for (int i = 0; i < 367; i++) {
            fact[i] = BigInteger.ZERO;
        }
        fact(366, fact);
        while (true) {
            int x = Integer.parseInt(br.readLine());
            int arr[] = new int[10];
            if (x == 0)
                break;
            String temp = fact[x].toString();
            for (int i = 0; i < temp.length(); i++) {
                if (temp.charAt(i) >= '0' && temp.charAt(i) <= '9') {
                    arr[temp.charAt(i) - '0']++;
                }
            }
            sb.append(x).append("! --\n");
            for (int i = 0; i < arr.length; i++) {
                sb.append("   (").append(i).append(")    ").append(arr[i]);
                if (i == 4 || i == 9)
                    sb.append("\n");
            }
        }
        System.out.print(sb);
    }

    static BigInteger fact(int x,  BigInteger[]arr) {
        if (x == 0) {
            return BigInteger.ONE;
        }
        if (arr[x].compareTo(BigInteger.ONE) == 1) {
            return arr[x];
        } else {
            arr[x] = BigInteger.valueOf(x).multiply(fact(x - 1, arr));
        }
        return arr[x];
    }
}
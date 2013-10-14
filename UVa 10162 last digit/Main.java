import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        int []arr = new int[100];
        BigInteger bg = new BigInteger("0");
        for (int i = 1; i < 100; i++) {
            bg = bg.add(BigInteger.valueOf(i).modPow(BigInteger.valueOf(i), BigInteger.valueOf(10)));
            arr[i] = bg.mod(BigInteger.valueOf(10)).intValue();
        }
        while (true) {
            String temp = br.readLine();
            BigInteger num = new BigInteger(temp);
            if (temp.equals("0")) {
                break;
            }
            int r = num.mod(BigInteger.valueOf(100)).intValue();
            sb.append(arr[r]).append("\n");
        }
        System.out.print(sb);
    }
}
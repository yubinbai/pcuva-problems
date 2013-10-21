import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        String m = "";
        int[] arr = new int[101];
        arr[0] = arr[1] = 1;
        arr[2] = 1;
        for (int i = 3; i < 101; i++) {
            arr[i] = BigInteger.valueOf(i).modPow(BigInteger.valueOf(i - 2),
                                                  BigInteger.valueOf(2000000011)).intValue();
        }
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            int x = Integer.parseInt(br.readLine());
            sb.append("Case #").append(i + 1).append(": ").append(arr[x]).append("\n");
        }
        System.out.print(sb);
    }
}
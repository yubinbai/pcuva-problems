import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            String[] str = br.readLine().split(" ");
            sb.append(new BigInteger(str[0]).subtract(new BigInteger(str[1]))).append("\n");
        }
        System.out.print(sb);
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        BigInteger[] bg = new BigInteger[5000];
        bg[0] = BigInteger.ZERO;
        bg[1] = BigInteger.ONE;
        int index = 1;
        do {
            index++;
            bg[index] = bg[index - 2].add(bg[index - 1]);
        } while (bg[index].toString().length() < 1001);
        String m = "";
        while ((m = br.readLine()) != null) {
            int temp = Integer.parseInt(m);
            sb.append(bg[temp]).append("\n");
        }
        System.out.print(sb);
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuilder sb = new StringBuilder("");
        String m = "";
        while (true) {
            m = br.readLine();
            if ("0".equals(m))
                break;
            int d = Integer.parseInt(m.charAt(m.length() - 1) + "");
            BigInteger dBig = BigInteger.valueOf(d).multiply(BigInteger.valueOf(5));
            m = m.substring(0, m.length() - 1);
            BigInteger rest = new BigInteger(m);
            if ((rest.subtract(dBig).mod(BigInteger.valueOf(17))).compareTo(BigInteger.ZERO) == 0)
                sb.append(1).append("\n");
            else
                sb.append(0).append("\n");
        }
        System.out.print(sb);
    }

}
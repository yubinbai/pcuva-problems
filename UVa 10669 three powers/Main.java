import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        BigInteger[] vals = new BigInteger[91];
        vals[0] = BigInteger.ONE;
        for (int i = 1; i < 91; i++) {
            vals[i] = vals[i - 1].multiply(BigInteger.valueOf(3));
        }
        while (true) {
            BigInteger val = new BigInteger(br.readLine());
            if (val.compareTo(BigInteger.ZERO) == 0)
                break;
            sb.append("{");
            val = val.subtract(BigInteger.ONE);
            int index = 0;
            boolean first = true;
            for (; val.compareTo(BigInteger.ZERO) > 0; val = val.divide(BigInteger.valueOf(2)), index++) {
                if (val.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE) == 0) {
                    if (!first)
                        sb.append(",");
                    first = false;
                    sb.append(" ").append(vals[index]);
                }
            }
            sb.append(" }\n");
        }
        System.out.print(sb);
    }
}
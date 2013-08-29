import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        StringBuffer sb = new StringBuffer("");
        while (s.hasNext()) {
            BigInteger x = s.nextBigInteger();
            String str = s.next();
            BigInteger y = s.nextBigInteger();
            BigInteger result = BigInteger.ZERO;
            if ("%".equals(str)) {
                result = x.mod(y);
            } else {
                result = x.divide(y);
            }
            sb.append(result).append("\n");
        }
        System.out.print(sb);
    }

}
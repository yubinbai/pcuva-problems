import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BigInteger bg = BigInteger.ZERO;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        String m = "";
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            br.readLine();
            if (i > 0)
                sb.append("\n");
            bg = new BigInteger(br.readLine());
            sb.append(bigsqrt(bg)).append("\n");
        }
        System.out.print(sb);
    }

    static BigInteger bigsqrt(BigInteger A) {
        boolean didWork;
        BigInteger temp = A.shiftRight(BigInteger.valueOf(A.bitLength()).shiftRight(1).intValue()), result = null;
        while (true) {
            result = temp.add(A.divide(temp)).shiftRight(1);
            if (!temp.equals(result))
                temp = result;
            else
                break;
        }
        didWork = false;
        if (result.multiply(result).equals(A))
            didWork = true;

        return result;
    }
}
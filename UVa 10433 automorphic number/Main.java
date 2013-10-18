import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String m = "";
        while ((m = br.readLine()) != null) {
            int val = checkBg(m);
            if (val == 0) {
                sb.append("Not an Automorphic number.\n");
            } else {
                sb.append(String.format("Automorphic number of %d-digit.\n", val));
            }
        }
        System.out.print(sb);
    }

    static int checkBg(String m) {

        BigInteger bg = new BigInteger(m);
        int n = m.length();
        String str = bg.modPow(BigInteger.valueOf(2), BigInteger.TEN.pow(n)).toString();
        if (str.equals("0") || str.equals("1"))
            return 0;
        while (str.length() != n) {
            str = "0" + str;
        }
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) != m.charAt(i))
                return 0;
        }
        return n;
    }
}
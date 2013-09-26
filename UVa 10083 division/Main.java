import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        String m = "";
        while ((m = br.readLine()) != null) {
            String[] str = m.split(" ");
            int t = Integer.parseInt(str[0]);
            int a = Integer.parseInt(str[1]);
            int b = Integer.parseInt(str[2]);

            //to check if the the result is the base is not equal to 0.
            if (t == 1) {
                sb.append("(").append(t).append("^").append(a).append("-1)/(").append(t).append("^").append(b).append("-1) ").append("is not an integer with less than 100 digits.\n");
                continue;
            }


            if (a == b) {
                sb.append("(").append(t).append("^").append(a).append("-1)/(").append(t).append("^").append(b).append("-1) ").append("1\n");
                continue;
            }

            //to check if the the result is an integer
            if (a % b != 0 || a < b) {
                sb.append("(").append(t).append("^").append(a).append("-1)/(").append(t).append("^").append(b).append("-1) ").append("is not an integer with less than 100 digits.\n");
                continue;
            }


            //to check if the the result is less than 100 digits
            if ( (a - b) * Math.log10(t) > 99) {
                sb.append("(").append(t).append("^").append(a).append("-1)/(").append(t).append("^").append(b).append("-1) ").append("is not an integer with less than 100 digits.\n");
                continue;
            }


            BigInteger bg = (BigInteger.valueOf(t).pow(a).subtract(BigInteger.ONE)).divide(BigInteger.valueOf(t).pow(b).subtract(BigInteger.ONE));

            sb.append("(").append(t).append("^").append(a).append("-1)/(").append(t).append("^").append(b).append("-1) ").append(bg).append("\n");
        }
        System.out.print(sb);
    }
}
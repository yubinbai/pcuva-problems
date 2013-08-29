import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main (String [] args) {

        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {

            BigDecimal bi = new BigDecimal(scan.next());
            int n = scan.nextInt();
            bi = bi.pow(n);
            String out = bi.stripTrailingZeros().toPlainString();
            if (out.charAt(0) == '0')
                out = out.substring(1, out.length());
            System.out.println(out);

        }
    }
}
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner (System.in);

        int testCase = input.nextInt();
        BigDecimal n1, n2;

        while ( testCase-- != 0 ) {
            n1 = BigDecimal.ZERO;
            n2 = BigDecimal.ZERO;
            do {
                n1 = n1.add(n2);
                n2 = input.nextBigDecimal();
            } while ( n2.compareTo(BigDecimal.ZERO) != 0 );

            char output [] = n1.toString().toCharArray();
            int len = output.length - 1;

            while ( len >= 0 && output [len] == '0' )
                len--;
            if ( len >= 0 && output [len] == '.' )
                len--;

            for ( int i = 0; i <= len; i++ )
                System.out.print (output [i]);
            System.out.println ();
        }
    }
}
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        try {
            // keep scanning until we run out of input, then fail quietly
            // by catching the exception
            while (true) {
                int first = scan.nextInt();
                int second = scan.nextInt();
                int start, end;

                // translate bounds as provided into lower & upper bound
                if (first < second) {
                    start = first;
                    end = second;
                } else {
                    start = second;
                    end = first;
                }

                // loop through range and store max
                int max = 0;
                int collatz = 0;
                for (int i = start; i <= end; i++) {
                    collatz = collatz(i);
                    if (collatz > max)
                        max = collatz;
                }

                // Output lower bound, upper bound, and max on a line
                System.out.printf("%d %d %d\n", first, second, max);
            }
        } catch (Exception e) {}
    }

    public static int collatz(int n) {
        // count from 1 since we always terminate at one, last sequence element
        int len = 1;
        // apply collatz rules until we reach one
        while (n != 1) {
            if (n % 2 == 1)
                n = 3 * n + 1;
            else
                n = n / 2;
            len++;
        }
        return len;
    }
}
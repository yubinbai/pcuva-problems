import java.io.*;
import java.util.*; // Scanner class is inside this package
import java.math.*; // BigInteger class is inside this package
class Main { /* UVa 10925 - Krakovia */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caseNo = 1;
        while (true) {
            int N = sc.nextInt(), F = sc.nextInt(); // N bills, F friends
            if (N == 0 && F == 0) break;
            BigInteger sum = BigInteger.valueOf(0); // use valueOf to initialize
            for (int i = 0; i < N; i++) { // sum the N large bills
                BigInteger V = sc.nextBigInteger(); // for reading next BigInteger!
                sum = sum.add(V); // this is BigInteger addition
            }
            System.out.println("Bill #" + (caseNo++) + " costs " +
                               sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(F)));
            System.out.println(); // the line above is BigInteger division
        }
    }
} // divide the large sum to F friends
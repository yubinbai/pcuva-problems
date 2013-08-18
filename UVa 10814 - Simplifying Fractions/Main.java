import java.io.*;
import java.util.*;
import java.math.*;
class Main { /* UVa 10814 - Simplifying Fractions */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        while (N-- > 0) {
            BigInteger p = sc.nextBigInteger();
            String ch = sc.next(); // ignore this one
            BigInteger q = sc.nextBigInteger();
            BigInteger gcd_pq = p.gcd(q); // wow :)
            System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq));
        }
    }
}
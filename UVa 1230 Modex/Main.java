import java.io.*;
import java.util.*;
import java.math.*;
class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int nTC = scan.nextInt();
        while (nTC-- > 0) {
            BigInteger x = BigInteger.valueOf(scan.nextInt());
            BigInteger y = BigInteger.valueOf(scan.nextInt());
            BigInteger n = BigInteger.valueOf(scan.nextInt());
            System.out.println(x.modPow(y, n)); // look ma, it’s in the library ;)
        }
    }
}
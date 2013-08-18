import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger[] factorials = new BigInteger[1001];
        factorials[0] = BigInteger.ONE;
        for (int i = 1; i < factorials.length; i++)
            factorials[i] = factorials[i - 1].multiply(new BigInteger(i + ""));
        while (in.hasNext()) {
            int n = Integer.parseInt(in.nextLine());
            System.out.println(n + "!");
            System.out.println(factorials[n]);
        }
    }
}
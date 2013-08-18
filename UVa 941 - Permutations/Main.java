import java.util.*;

public class Main {
    public static long factorial(int n) {
        long res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    public static String nThPermutation(String s, long n) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder(new String(arr));
        String res = "";
        while (n != 0) {
            int k = (int) (n / factorial(sb.length() - 1));
            long mod = n % factorial(sb.length() - 1);
            res = res + sb.charAt(k);
            sb.deleteCharAt(k);
            n = mod;
        }
        return res + sb;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int TC = in.nextInt();
        while (TC-- > 0) {
            String s = in.next();
            long n = in.nextLong();
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            System.out.println(nThPermutation(new String(arr), n));
        }
    }
}
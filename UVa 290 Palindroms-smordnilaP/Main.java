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
            int index = minBase(m);
            if (index < 2)
                index = 2;
            if (!isPalindrome(m)) {
                for (int i = 15; i > index - 1; i--) {
                    if (i < 15)
                        sb.append(" ");
                    sb.append(baseCount(m, i, 1));
                }
            } else {
                for (int i = 15; i > index - 1; i--) {
                    if (i < 15)
                        sb.append(" ");
                    sb.append("0");
                }
            }
            for (int i = 2; i < index; i++) {
                sb.append(" ").append("?");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static int minBase(String temp) {
        int max = -1;
        temp = temp.toUpperCase();
        for (int i = 0; i < temp.length(); i++) {
            if (temp.charAt(i) >= 'A' && temp.charAt(i) <= 'Z' ) {
                if (max < temp.charAt(i) - 'A' + 10)
                    max = temp.charAt(i) - 'A' + 10;
            } else if (temp.charAt(i) >= '0' && temp.charAt(i) <= '9' ) {
                if (max < temp.charAt(i) - '0')
                    max = temp.charAt(i) - '0';
            }
        }
        return max + 1;
    }

    static boolean isPalindrome(String s) {
        for (int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    static int baseCount(String x, int base, int i) {
        BigInteger first = new BigInteger(x, base);
        BigInteger second = new BigInteger(new StringBuilder(x).reverse().toString(), base);
        BigInteger last = first.add(second);
        String str = last.toString(base);
        if (isPalindrome(str))
            return i;
        return baseCount(str, base, ++i);
    }
}
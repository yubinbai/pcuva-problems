import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            String[] str = br.readLine().split(" ");
            BigDecimal bd1 = new BigDecimal(str[0]);
            bd1 = bd1.add(new BigDecimal(str[1]));
            StringBuilder temp = new StringBuilder(bd1.toString());
            sb.append(zeros(temp)).append("\n");
        }
        System.out.print(sb);
    }
    static String zeros(StringBuilder s) {
        int index = s.length() - 1;
        while (s.charAt(index) == '0' && s.charAt(index - 1) != '.') {
            index--;
        }

        return s.substring(0, index + 1);
    }
}
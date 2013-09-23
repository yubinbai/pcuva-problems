import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            String str = br.readLine();
            int n1 = (str.charAt(0) - 'A') * 26 * 26;
            n1 += (str.charAt(1) - 'A') * 26;
            n1 += (str.charAt(2) - 'A');
            int n2 = (str.charAt(4) - '0') * 1000;
            n2 += (str.charAt(5) - '0') * 100;
            n2 += (str.charAt(6) - '0') * 10;
            n2 += (str.charAt(7) - '0');
            if (Math.abs(n1 - n2) > 100) {
                sb.append("not nice\n");
            } else {
                sb.append("nice\n");
            }
        }
        System.out.print(sb);
    }

}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int cases = 1;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int sum = 0;
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) {
                break;
            }
            sb.append("Case ").append(cases).append(":\n");
            cases++;
            while (st.hasMoreTokens()) {
                sum += Integer.parseInt(st.nextToken());
            }
            if (sum < 0) {
                if (sum % n == 0) {
                    sb.append("- ").append(Math.abs(sum / n)).append("\n");
                } else {
                    int val = (Math.abs(sum / n));
                    String qu = "";
                    if (val != 0)
                        qu += val;
                    int num = sum % n;
                    int gcd = gcd(num, n);
                    String numS = (Math.abs(num / gcd)) + "";
                    String denS = Math.abs(n / gcd) + "";
                    for (int i = 0; i < qu.length() + denS.length() - numS.length() + 2; i++) {
                        sb.append(" ");
                    }
                    sb.append(numS).append("\n");

                    sb.append("- ");
                    sb.append(qu);
                    for (int i = 0; i < denS.length(); i++) {
                        sb.append("-");
                    }
                    sb.append("\n");

                    for (int i = 0; i < qu.length() + 2; i++) {
                        sb.append(" ");
                    }
                    sb.append(denS).append("\n");
                }
            } else {
                if (sum % n == 0) {
                    sb.append(sum / n).append("\n");
                } else {
                    int val = (Math.abs(sum / n));
                    String qu = "";
                    if (val != 0)
                        qu += val;
                    int num = sum % n;
                    int gcd = gcd(num, n);
                    String numS = (Math.abs(num / gcd)) + "";
                    String denS = (n / gcd) + "";
                    for (int i = 0; i < qu.length() + denS.length() - numS.length(); i++) {
                        sb.append(" ");
                    }
                    sb.append(numS).append("\n");

                    sb.append(qu);
                    for (int i = 0; i < denS.length(); i++) {
                        sb.append("-");
                    }
                    sb.append("\n");

                    for (int i = 0; i < qu.length(); i++) {
                        sb.append(" ");
                    }
                    sb.append(denS).append("\n");
                }
            }
        }
        System.out.print(sb);
    }

    static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }
}
//Root finding algorithm using newton method
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        String m = "";
        while ((m = br.readLine()) != null) {
            if ("#".equals(m.trim()))
                break;
            StringTokenizer st = new StringTokenizer(m);
            int p = Integer.parseInt(st.nextToken()),
                q = Integer.parseInt(st.nextToken()),
                r = Integer.parseInt(st.nextToken()),
                s = Integer.parseInt(st.nextToken()),
                t = Integer.parseInt(st.nextToken()),
                u = Integer.parseInt(st.nextToken());
            if (function(0, p, q, r, s, t, u) * function(1, p, q, r, s, t, u) > 0) {
                sb.append("No solution\n");
            } else {
                sb.append(String.format("%.4f\n", netwonMethod(p, q, r, s, t, u)));
            }
        }
        System.out.print(sb);
    }
    static double function(double i, int p, int q, int r,
                           int s, int t, int u) {
        return 1.0 * p * Math.exp(-i) + 1.0 * q * Math.sin(i)
               + 1.0 * r * Math.cos(i) + 1.0 * s * Math.tan(i) + t * i * i + u;
    }

    static double dfunction(double i, int p, int q, int r,
                            int s, int t, int u) {
        return -1.0 * p * Math.exp(-i) + 1.0 * q * Math.cos(i)
               - 1.0 * r * Math.sin(i) + 1.0 * s / (Math.cos(i) * Math.cos(i)) + 2 * t * i;
    }

    static double netwonMethod(int p, int q, int r,
                               int s, int t, int u) {
        if (function(0, p, q, r, s, t, u) == 0)
            return 0;
        double ans = 0.5;
        while (true) {
            double newans = ans - function(ans, p, q, r, s, t, u) / dfunction(ans, p, q, r, s, t, u);
            if (Math.abs(newans - ans) < eps)
                return ans;
            ans = newans;
        }
    }
    static double eps = 1E-7;
}
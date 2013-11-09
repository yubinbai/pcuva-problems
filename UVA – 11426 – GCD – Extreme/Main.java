import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
public class Main {
    public static void main(String[] args) throws NumberFormatException,
        IOException {
        long[] g = new long[200001];
        for (int i = 2; i < g.length; i++) {
            g[i] = g[i - 1];
            TreeSet<Integer> factors = new TreeSet<Integer>();
            for (int j = 1; j * j <= i; j++)
                if (i % j == 0) {
                    factors.add(j);
                    factors.add(i / j);
                }
            int[] arr = new int[factors.size()];
            int[] vals = new int[factors.size()];
            int t = 0;
            for (int j : factors)
                vals[t++] = j;
            for (int j = 0; j < arr.length; j++)
                arr[j] = (i - 1) / vals[j];
            for (int j = vals.length - 1; j >= 0; j--)
                for (int k = j + 1; k < vals.length; k++)
                    if (vals[k] % vals[j] == 0)
                        arr[j] -= arr[k];
            for (int j = 0; j < arr.length; j++)
                g[i] += arr[j] * vals[j];
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String s = in.readLine();
            s = s.trim();
            int n = Integer.parseInt(s);
            if (n == 0)
                break;
            System.out.println(g[n]);
        }
    }
}
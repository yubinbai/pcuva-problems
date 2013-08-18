import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = null;

        boolean first = true;
        int test = 1;
        String line = null;
        while (true) {
            line = br.readLine();
            if (line == null)
                break;
            st = new StringTokenizer(line);
            String s1 = st.nextToken();
            String s2 = st.nextToken();
            if (solve(s1, s2))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
        out.close();
        br.close();
    }
    public static boolean solve(String s1, String s2) {
        int N = s1.length();
        int M = s2.length();
        if (M < N)
            return false;
        int i = 0, j = 0;
        for (j = 0; j < M; j++) {
            if (i == N)
                return true;
            if (s1.charAt(i) == s2.charAt(j))
                i++;
        }
        return (i == N);

    }
}
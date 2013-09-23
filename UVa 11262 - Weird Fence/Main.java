import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static int bfs(int s, int t, int[][] res, int[] parent) {
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        Q.add(Integer.MAX_VALUE);
        while (!Q.isEmpty()) {
            int n = Q.poll();
            int flow = Q.poll();
            if (n == t)
                return flow;
            for (int j = 0; j < res[n].length; j++) {
                if (res[n][j] != 0 && parent[j] == -1) {
                    Q.add(j);
                    Q.add(Math.min(flow, res[n][j]));
                    parent[j] = n;
                }
            }
        }
        return 0;
    }

    public static void augmentPath(int s, int t, int flow, int[] parent,
                                   int[][] res) {
        int cur = t;
        while (cur != s) {
            res[parent[cur]][cur] -= flow;
            res[cur][parent[cur]] += flow;
            cur = parent[cur];
        }
    }

    public static int maxFlow(int s, int t, int[][] res) {
        int[] parent = new int[res.length];
        Arrays.fill(parent, -1);
        int flow, maxflow = 0;
        while ((flow = bfs(s, t, res, parent)) != 0) {
            maxflow += flow;
            augmentPath(s, t, flow, parent, res);
            Arrays.fill(parent, -1);
        }
        return maxflow;
    }

    public static void main(String[] args) throws Exception {
        InputReader in = new InputReader(System.in);
        int tc = in.nextInt();
        while (tc-- > 0) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            boolean[] col = new boolean[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                String s = in.next();
                col[i] = s.equals("red");
            }

            int l = 0;
            int h = 3000;
            boolean ok = false;
            while (h > l) {
                int mid = (l + h) / 2;
                int[][] g = new int[n + 2][n + 2];
                for (int i = 0; i < n; i++) {
                    if (col[i])
                        g[0][i + 1] = 1;
                    else
                        g[i + 1][n + 1] = 1;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (col[i]
                                && !col[j]
                                && (x[i] - x[j]) * (x[i] - x[j])
                                + (y[i] - y[j]) * (y[i] - y[j]) <= mid
                                * mid) {
                            g[i + 1][j + 1] = 1;
                        }
                    }
                }
                int max = maxFlow(0, n + 1, g);
                if (max >= k) {
                    h = mid;
                    ok = true;
                } else
                    l = mid + 1;
            }
            if (ok)
                System.out.println(h);
            else
                System.out.println("Impossible");
        }
    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] freq = new int[200001];
    static int[] start = new int[200001];
    static int[] input = new int[200001];

    static class SegmentTree {
        private int[] tree;
        private int length;

        public SegmentTree(int[] a) {
            length = a.length;
            int len = a.length - 1;
            int pow = 1;
            while (len != 0) {
                pow = len & -len;
                len -= pow;
            }
            if (pow != length)
                pow <<= 1;
            tree = new int[pow | (pow - 1)];
            build(a, 0, 0, a.length - 1);
        }

        public int build(int[] a, int i, int s, int t) {
            if (s == t)
                return tree[i] = a[s];
            else
                return tree[i] = func(build(a, 2 * i + 1, s, (s + t) / 2),
                                      build(a, 2 * i + 2, (s + t) / 2 + 1, t));
        }

        public int query(int lo, int hi) {
            return query(0, 0, length - 1, lo, hi);
        }

        public int query(int i, int s, int t, int lo, int hi) {
            if (s == lo && t == hi)
                return tree[i];
            int mid = (s + t) / 2;
            if (lo > mid)
                return query(i * 2 + 2, mid + 1, t, lo, hi);
            else if (hi <= mid)
                return query(i * 2 + 1, s, mid, lo, hi);
            else
                return func(query(i * 2 + 1, s, mid, lo, mid),
                            query(i * 2 + 2, mid + 1, t, mid + 1, hi));
        }

        public int func(int a, int b) {
            return Math.max(a, b);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader inp = new BufferedReader(
            new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        while (true) {
            String t = inp.readLine();
            StringTokenizer st = new StringTokenizer(t, " ");
            int n = Integer.parseInt(st.nextToken());
            if (n == 0)
                break;
            int q = Integer.parseInt(st.nextToken());
            Arrays.fill(freq, 0);
            st = new StringTokenizer(inp.readLine(), " ");
            for (int i = 0; i < n; i++) {
                int k = Integer.parseInt(st.nextToken());
                if (freq[k + 100000] == 0) {
                    start[k + 100000] = i;
                }
                freq[k + 100000]++;
                input[i] = k;
            }
            SegmentTree s = new SegmentTree(freq);
            for (int i = 0; i < q; i++) {
                st = new StringTokenizer(inp.readLine(), " ");
                int a = Integer.parseInt(st.nextToken()) - 1;
                int b = Integer.parseInt(st.nextToken()) - 1;
                int k1 = input[a];
                int k2 = input[b];
                int optimal;
                if (k1 == k2) {
                    optimal = b - a + 1;
                } else {

                    int k1Val = (freq[k1 + 100000] == 0) ? 0
                                : freq[k1 + 100000] - (a - start[k1 + 100000]);
                    int k2Val = (freq[k2 + 100000] == 0) ? 0 : b
                                - start[k2 + 100000] + 1;
                    optimal = Math.max(k1Val, k2Val);
                }
                k1++;
                k2--;
                if (k1 <= k2) {
                    optimal = Math.max(optimal,
                                       s.query(k1 + 100000, k2 + 100000));
                }
                out.append(optimal + "\n");
            }
        }
        System.out.print(out);
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            int[]x = new int[Integer.parseInt(str[0])];
            for (int j = 0; j < x.length; j++) {
                x[j] = Integer.parseInt(str[j + 1]);
            }
            str = br.readLine().split(" ");
            int[]y = new int[Integer.parseInt(str[0])];
            for (int j = 0; j < y.length; j++) {
                y[j] = Integer.parseInt(str[j + 1]);
            }
            sb.append(LCIS(x, y)).append("\n");
        }
        System.out.print(sb);
    }

    static int LCIS(int[]x, int[]y) {
        int N = x.length, M = y.length;
        int []common = new int[1501], previous = new int[1501];
        int current, last;
        for (int i = 0; i < N; i++) {
            current = 0;
            last = -1;
            for (int j = 0; j < M; j++) {
                if (x[i] == y[j] && current >= common[j]) {
                    common[j] = current + 1;
                    previous[j] = last;
                }
                if (x[i] > y[j] && current < common[j]) {
                    current = common[j];
                    last = j;
                }
            }
        }

        int l = 0, ind = -1;
        for (int i = 0; i < M; i++)
            if (common[i] > l) {
                l = common[i];
                ind = i;
            }
        return l;
    }

}
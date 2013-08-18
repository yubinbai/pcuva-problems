/**
 * @problemId 10026
 * @problemName Shoemaker's Problem
 * @judge http://uva.onlinejudge.org/
 * @category greedy
 **/
import java.io.*;
import java.util.*;
import static java.lang.Integer.*;
public class Main {
    public static void main(String args[]) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int C = parseInt(in.readLine().trim());
        for (int c = 0; c < C; c++) {
            in.readLine();
            int T = parseInt(in.readLine().trim());
            double[][] arr = new double[T][];
            for (int t = 0, s; t < T; t++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                s = parseInt(st.nextToken());
                arr[t] = new double[] {1.0 * parseInt(st.nextToken()) / s, t + 1};
            }
            Arrays.sort(arr, new Comparator<double[]>() {
                public int compare(double[] o1, double[] o2) {
                    if (o1[0] != o2[0])return o2[0] < o1[0] ? -1 : 1;
                    return (o1[1] + "").compareTo(o2[1] + "");
                }
            });
            for (int i = 0; i < T; i++)
                System.out.print((int)arr[i][1] + (i < T - 1 ? " " : ""));
            System.out.println(c < C - 1 ? "\n" : "");
        }
    }
}
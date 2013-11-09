import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            StringTokenizer str = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(str.nextToken());
            int B = Integer.parseInt(str.nextToken());
            int C = Integer.parseInt(str.nextToken());
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for (int j = 1; j < (B / 2) + 1; j++) {
                if (B % j == 0) {
                    arr.add(j);
                    arr.add(-j);
                }
            }
            arr.add(B);
            arr.add(-B);
            Collections.sort(arr);
            boolean flag = false;
            for (int x = 0; x < arr.size(); x++) {
                for (int y = x + 1; y < arr.size(); y++) {
                    for (int z = y + 1; z < arr.size(); z++) {
                        if (arr.get(x) * arr.get(y) * arr.get(z) == B) {
                            if (arr.get(x) + arr.get(y) + arr.get(z) == A) {
                                if ((arr.get(x) * arr.get(x)) +
                                        (arr.get(y) * arr.get(y)) +
                                        (arr.get(z) * arr.get(z)) == C) {
                                    sb.append(arr.get(x)).append(" ")
                                    .append(arr.get(y)).append(" ")
                                    .append(arr.get(z)).append("\n");
                                    flag = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (!flag) {
                sb.append("No solution.").append("\n");
            }
        }
        System.out.print(sb);
    }
}
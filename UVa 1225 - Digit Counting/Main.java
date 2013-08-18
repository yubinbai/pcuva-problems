import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        StringBuilder seq = new StringBuilder("");
        int cases = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < cases; i++) {
            int x = Integer.parseInt(br.readLine().trim());
            seq = new StringBuilder("");
            for (int j = 1; j < x + 1; j++) {
                seq.append(j);
            }
            int[] arr = count(seq);
            for (int j = 0; j < arr.length; j++) {
                if (j > 0)
                    sb.append(" ");
                sb.append(arr[j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static int[] count(StringBuilder sb) {
        int[] arr = new int[10];
        for (int i = 0; i < sb.length(); i++) {
            arr[sb.charAt(i) - '0']++;
        }
        return arr;
    }
}
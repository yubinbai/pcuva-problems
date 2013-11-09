import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            st.nextToken();
            int y = Integer.parseInt(st.nextToken());
            st.nextToken();
            int z = Integer.parseInt(st.nextToken());
            sb.append(getbase(x, y, z)).append("\n");
            String m = "";
        }
        System.out.print(sb);
    }
    static int getbase(int x, int y, int z) {
        if (checkones(x + "") && checkones(y + "") && checkones(z + "")) {
            if ((x + "").length() + (y + "").length() == (z + "").length())
                return 1;
        }
        for (int i = Math.max(Math.max(minbase(x + ""), minbase(y + "")), minbase(z + "")); i < 19; i++) {
            int x2 = Integer.parseInt(x + "", i);
            int y2 = Integer.parseInt(y + "", i);
            int z2 = Integer.parseInt(z + "", i);
            if (x2 + y2 == z2) {
                return i;
            }
        }
        return 0;
    }
    static boolean checkones(String val) {
        for (int i = 0; i < val.length(); i++) {
            if (val.charAt(i) != '1')
                return false;
        }
        return true;
    }
    static int minbase(String val) {
        int max = 1;
        for (int i = 0; i < val.length(); i++) {
            int temp = val.charAt(i) - '0';
            if (temp > max)
                max = temp;
        }
        return max + 1;
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        String m = "", ref = "";
        String match = "the quick brown fox jumps over the lazy dog";
        LinkedList<String> list = new LinkedList<String>();
        int cases = Integer.parseInt(br.readLine());
        br.readLine();
        for (int j = 0; j < cases; j++) {
            list.clear();
            boolean flag = false, found = false;
            if (j > 0)
                sb.append("\n");
            while (true) {
                if ((m = br.readLine()) == null) {
                    break;
                }
                if (m.trim().equals("")) {
                    break;
                }
                list.add(m);
                if (m.length() == match.length() && !flag && !found) {
                    flag = true;
                    for (int i = 0; i < m.length(); i++) {
                        if (m.charAt(i) == (' ') && match.charAt(i) != (' ')) {
                            flag = false;
                            break;
                        } else if (m.charAt(i) != (' ') && match.charAt(i) == (' ')) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        flag = canBe(m, match);
                }
                if (flag && !found) {
                    ref = m;
                    found = true;
                }
            }
            if (!flag) {
                sb.append("No solution.\n");
            } else {
                char []enc = getEnc(ref, match);
                for (int i = 0; i < list.size(); i++) {
                    String temp = list.get(i);
                    for (int z = 0; z < temp.length(); z++) {
                        if (temp.charAt(z) >= 'a' && temp.charAt(z) <= 'z') {
                            sb.append(enc[temp.charAt(z) - 97]);
                        } else {
                            sb.append(temp.charAt(z));
                        }
                    }
                    sb.append("\n");
                }

            }
        }
        System.out.print(sb);
    }

    static boolean canBe(String x, String in) {
        boolean[] arr = new boolean[26];
        char[] arr2 = new char[26];
        for (int i = 0; i < x.length(); i++) {
            if (x.charAt(i) >= 'a' && x.charAt(i) <= 'z')
                if (!arr[x.charAt(i) - 97]) {
                    arr[x.charAt(i) - 97] = true;
                    arr2[x.charAt(i) - 97] = in.charAt(i);
                } else {
                    if (arr2[x.charAt(i) - 97] != in.charAt(i)) {
                        return false;
                    }
                }
        }
        return true;
    }

    static char[]getEnc(String x, String in) {
        char[] arr = new char[26];
        for (int i = 0; i < x.length(); i++) {
            if (x.charAt(i) >= 'a' && x.charAt(i) <= 'z')
                arr[x.charAt(i) - 97] = in.charAt(i);
        }
        return arr;
    }
}
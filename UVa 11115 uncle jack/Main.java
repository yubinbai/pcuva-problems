import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");

        while (true) {
            String []str = br.readLine().split(" ");
            int i = Integer.parseInt(str[0]);
            int j = Integer.parseInt(str[1]);
            if (i == 0 && j == 0)
                break;
            sb.append((BigInteger.valueOf(i)).pow(j)).append("\n");
        }
        System.out.print(sb);
    }
}
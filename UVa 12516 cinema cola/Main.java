import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        boolean arr[][] = new boolean[27][100];
        boolean seats[][] = new boolean[27][100];
        while (true) {
            StringTokenizer str = new StringTokenizer(br.readLine());
            int rows = Integer.parseInt(str.nextToken());
            int cols = Integer.parseInt(str.nextToken());
            if (rows == 0 && cols == 0) {
                break;
            }
            for (int i = 0; i < 27; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = seats[i][j] = false;
                }
            }
            int alreadyIn = Integer.parseInt(br.readLine());
            for (int j = 0; j < alreadyIn; j++) {
                str = new StringTokenizer(br.readLine());
                StringBuilder temp = new StringBuilder(str.nextToken());
                int rowIn = temp.charAt(0) - 65;
                int colIn = Integer.parseInt(temp.substring(1));
                temp = new StringBuilder(str.nextToken());
                if (temp.charAt(0) == '-') {
                    arr[rowIn][colIn - 1] = true;
                } else {
                    arr[rowIn][colIn] = true;
                }
            }
            int myGroup = Integer.parseInt(br.readLine());
            for (int j = 0; j < myGroup; j++) {
                str = new StringTokenizer(br.readLine());
                StringBuilder temp = new StringBuilder(str.nextToken());
                int rowIn = temp.charAt(0) - 65;
                int colIn = Integer.parseInt(temp.substring(1));
                seats[rowIn][colIn] = true;
            }
            boolean canWe = true;
            for (int j = 0; j < rows; j++) {
                for (int z = 1; z < cols + 1; z++) {
                    if (seats[j][z]) {
                        if (!arr[j][z - 1]) {
                            arr[j][z - 1] = true;
                        } else if (!arr[j][z]) {
                            arr[j][z] = true;
                        } else {
                            canWe = false;
                            break;
                        }
                    }
                    if (!canWe)
                        break;
                }
            }
            if (canWe) {
                sb.append("YES").append("\n");
            } else {
                sb.append("NO").append("\n");
            }
        }
        System.out.print(sb);
    }
}
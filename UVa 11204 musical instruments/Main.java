import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            String str[] = br.readLine().split(" ");
            int inst = Integer.parseInt(str[0]);
            int stud = Integer.parseInt(str[1]);
            int std[][] = new int[stud][inst];
            int arr[] = new int[inst];
            for (int j = 0; j < stud; j++) {
                str = br.readLine().split(" ");
                for (int z = 0; z < str.length; z++) {
                    std[j][z] = Integer.parseInt(str[z]);
                }
            }
            for (int j = 0; j < stud; j++) {
                for (int z = 0; z < inst; z++) {
                    if (std[j][z] == 1)
                        arr[z]++;
                }
            }
            int rs = 1;
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] > 1)
                    rs *= arr[j];
            }
            sb.append(rs).append("\n");
        }
        System.out.print(sb);
    }
}
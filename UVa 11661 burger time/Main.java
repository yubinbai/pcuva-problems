import java.io.PrintWriter;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        while (sc.hasNextLine()) {
            int L = Integer.parseInt(sc.nextLine());
            if (L == 0)
                break;
            char[] road = sc.nextLine().toCharArray();
            int lastDrugStore = -1;
            int lastRestaurant = -1;
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < road.length; i++) {
                if (road[i] == 'R') {
                    lastRestaurant = i;
                } else if (road[i] == 'D') {
                    lastDrugStore = i;
                } else if (road[i] == 'Z') {
                    min = 0;
                    break;
                }
                if (lastDrugStore != -1 && lastRestaurant != -1) {
                    min = Math.min(Math.abs(lastDrugStore - lastRestaurant), min);
                }
            }
            out.println(min);
        }
        out.close();
        sc.close();
    }
}

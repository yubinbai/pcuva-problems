import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            int n = in.nextInt();
            System.out.println(ones(n));
        }
    }
    public static int ones(int n) {
        int curr = 1;
        int counter = 1;
        while (curr % n != 0) {
            curr *= 10;
            curr++;
            curr %= n;
            counter++;
        }
        return counter;
    }
}
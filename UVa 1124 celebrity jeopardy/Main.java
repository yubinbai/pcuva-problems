import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        while (sc.hasNextLine()) {
            out.println(sc.nextLine());
        }
        out.close();
        sc.close();
    }

}

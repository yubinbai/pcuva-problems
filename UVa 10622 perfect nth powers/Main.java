import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
public class Main {
    public static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        boolean[] isPrime = new boolean[1 << 16];
        isPrime[0] = isPrime[1] = true;
        for (int i = 2; i * i < isPrime.length; i++)
            if (!isPrime[i])
                for (int j = i * i; j < isPrime.length; j += i)
                    isPrime[j] = true;
        LinkedList<Integer> res = new LinkedList<Integer>();
        for (int i = 2; i < isPrime.length; i++)
            if (!isPrime[i])
                res.add(i);
        while (true) {
            long t = Long.parseLong(in.readLine());
            if (t == 0)
                break;
            long sign = t / Math.abs(t);
            t = Math.abs(t);
            int g = 0;
            for (int i : res) {
                if (t % i == 0) {
                    int c = 0;
                    while (t % i == 0) {
                        t /= i;
                        c++;
                    }
                    g = gcd(c, g);
                }
                if (t == 1)
                    break;
            }
            if (t != 1)
                g = gcd(1, g);
            while (sign < 0 && g % 2 == 0)
                g /= 2;
            System.out.println(g);
        }
    }
}
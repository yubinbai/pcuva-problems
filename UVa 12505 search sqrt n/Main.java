import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.MathContext;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        String m = "";
        int cases = Integer.parseInt(br.readLine());
        for (int i = 0; i < cases; i++) {
            String str[] = br.readLine().split(" ");
            BigDecimal bd = new BigDecimal(Integer.parseInt(str[0]));
            BigDecimal temp = sqrt(bd, new MathContext(100));
            String find = bigBin(temp);
            int index = find.indexOf(str[1]);
            sb.append(index).append("\n");
        }
        System.out.print(sb);
    }

    public static BigDecimal sqrt(BigDecimal x, MathContext mc) {
        BigDecimal g = x.divide(BigDecimal.valueOf(2), mc);
        boolean done = false;
        final int maxIterations = mc.getPrecision() + 1;
        for (int i = 0; !done && i < maxIterations; i++) {
            BigDecimal r = x.divide(g, mc);
            r = r.add(g);
            r = r.divide(BigDecimal.valueOf(2), mc);
            done = r.equals(g);
            g = r;
        }
        return g;
    }

    static String bigBin(BigDecimal x) {
        String[] str = x.toPlainString().split("\\.");
        str[1] = "0." + str[1];
        BigDecimal bd = new BigDecimal(str[1]);
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < 121; i++) {
            bd = bd.multiply(BigDecimal.valueOf(2));
            if (bd.compareTo(BigDecimal.ONE) > -1) {
                bd = bd.subtract(BigDecimal.ONE);
                sb.append("1");
            } else {
                sb.append("0");
            }
        }
        return sb.toString();
    }
}
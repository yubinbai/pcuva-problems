import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = null;

        boolean first = true;
        int test = 1;
        String line = null;
        while (true) {
            line = br.readLine();
            if (line == null)
                break;
            st = new StringTokenizer(line);
            int N = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            if (N == 0 && P == 0)
                break;
            if (!first)
                out.println();
            for (int i = 0; i < N; i++) {
                br.readLine();
            }

            PriorityQueue<Offer> heap = new PriorityQueue<Offer>(P, new Comparator<Offer>() {
                @Override
                public int compare(Offer arg0, Offer arg1) {
                    if (arg0.compliance == arg1.compliance) {
                        if (arg0.price == arg1.price) {
                            return arg0.idx < arg1.idx ? -1 : 1;
                        } else {
                            return arg0.price < arg1.price ? -1 : 1;
                        }
                    } else {
                        return arg1.compliance < arg0.compliance ? -1 : 1;
                    }
                }
            });

            for (int i = 0; i < P; i++) {
                String name = br.readLine();
                st = new StringTokenizer(br.readLine());
                double price = Double.parseDouble(st.nextToken());
                int offer = Integer.parseInt(st.nextToken());
                for (int j = 0; j < offer; j++) {
                    br.readLine();
                }
                heap.add(new Offer(name, price, offer, i));
            }
            out.println("RFP #" + test);
            out.println(heap.poll().name);
            test++;
            first = false;
        }

        out.close();
        br.close();
    }

    private static class Offer {
        int idx;
        String name;
        double price;
        double compliance;

        public Offer(String name, double price, double compliance, int idx) {
            this.name = name;
            this.price = price;
            this.compliance = compliance;
            this.idx = idx;
        }
    }

}
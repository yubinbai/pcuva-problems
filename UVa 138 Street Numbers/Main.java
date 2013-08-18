/**
 * 138 Street Numbers: 先憑實力再耍賤 (小心第二數扣除10字元的排版外沒有空白, 如果完全憑實力 5436ms)
 * 測驗結果: 0.090 ms
 * 測驗日期: 2008-10-16
 *
 * 導公式得知 2k^2 = n^2+n
 *
 * 若已知 k 則
 *
 *      -1 + sqrt(1+8k^2)
 * n = -------------------
 *             2
 *
 * 1+8k^2 若為完全平方數則有解
 *
 * @author Raymond Wu (小璋丸)
 */
public class Main {

    public static void main(String[] args) {
        // 憑實力
        /*
        long k = 2;
        long n;
        long chk;
        double root;
        int count = 0;

        long begin = System.currentTimeMillis();
        while(count<10) {
                chk = ((k*k)<<3)|1;
                root = Math.sqrt(chk);
                if(root==Math.floor(root)) {
                        n = (long)(root-1)>>1;
                        System.out.printf("%10d%10d\n",k,n);
                        count++;
                }
                k++;
        }
        long elapsed = System.currentTimeMillis() - begin;
        System.out.println(elapsed+"ms");
        */

        // 耍賤
        String output =
            "         6         8\n" +
            "        35        49\n" +
            "       204       288\n" +
            "      1189      1681\n" +
            "      6930      9800\n" +
            "     40391     57121\n" +
            "    235416    332928\n" +
            "   1372105   1940449\n" +
            "   7997214  11309768\n" +
            "  46611179  65918161";

        System.out.println(output);
    }

}
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Arrays;

/*
 LCD Display
PC/UVa IDs: 110104/706, Popularity: A, Success rate: average Level: 1
 */
public class Main {
    private static final char SPACE = ' ', VERTICAL = '|', HORIZONTAL = '-';
    private static final byte[] BITMAP = {0077, 0024, 0155, 0165, 0126, 0163, 0173, 0025, 0177, 0167};

    public static void main(String[] args) {
        run(System.in, System.out);
    }

    private static void run(InputStream input, PrintStream out) {
        Scanner inputScanner = new Scanner(input);
        while (inputScanner.hasNext()) {
            int size = inputScanner.nextInt();
            String number = inputScanner.next();

            if ((size == 0) && (number.equals("0"))) {
                break;
            }

            out.printf("%s\n", getLCDString(size, number));
        }
    }

    private static String getLCDString(int size, String number) {
        final int numberOfChar = number.length();
        String[][] buffer = new String[numberOfChar][];
        for (int i = 0; i < numberOfChar; i++) {
            buffer[i] = getLCDDigit(size, number.charAt(i));
        }

        final int totalHeight = 2 * size + 3;
        StringBuilder sb = new StringBuilder();
        for (int row = 0; row < totalHeight; row++) {
            for (int charIndex = 0; charIndex < numberOfChar; charIndex++) {
                sb.append(buffer[charIndex][row]);
                if (charIndex < numberOfChar - 1) sb.append(SPACE);
            }
            sb.append("\n"); //new line for next row
        }

        return sb.toString();
    }

    private static String[] getLCDDigit(int size, char c) {
        final int totalHeight = 2 * size + 3;
        String[] rows = new String[totalHeight];

        char[] charBuffer = new char[size];
        byte bitmap = BITMAP[c - '0'];

        //first row
        Arrays.fill(charBuffer,  (bitmap & 0001) > 0 ? HORIZONTAL : SPACE);
        StringBuilder sb = new StringBuilder();
        rows[0] = sb.append(SPACE).append(String.valueOf(charBuffer)).append(SPACE).toString();

        //middle row
        sb = new StringBuilder();
        Arrays.fill(charBuffer, (bitmap & 0100) > 0 ? HORIZONTAL : SPACE);
        rows[size + 1] = sb.append(SPACE).append(String.valueOf(charBuffer)).append(SPACE).toString();

        //bottom row
        sb = new StringBuilder();
        Arrays.fill(charBuffer, (bitmap & 0040) > 0 ? HORIZONTAL : SPACE);
        rows[2 * size + 2] = sb.append(SPACE).append(String.valueOf(charBuffer)).append(SPACE).toString();

        //top half
        sb = new StringBuilder();
        Arrays.fill(charBuffer, SPACE);
        Arrays.fill(rows, 1, size + 1, sb.append((bitmap & 0002) > 0 ? VERTICAL : SPACE).append(String.valueOf(charBuffer)).append((bitmap & 0004) > 0 ? VERTICAL : SPACE).toString());

        //bottom half
        sb = new StringBuilder();
        Arrays.fill(charBuffer, SPACE);
        Arrays.fill(rows, size + 2, 2 * size + 2, sb.append((bitmap & 0010) > 0 ? VERTICAL : SPACE).append(String.valueOf(charBuffer)).append((bitmap & 0020) > 0 ? VERTICAL : SPACE).toString());

        return rows;
    }
}
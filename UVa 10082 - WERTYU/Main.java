import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String keyboard = "  `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        for (int b = 1; b < keyboard.length(); b++) {
            map.put(keyboard.charAt(b), keyboard.charAt(b - 1));
        }
        while (in.hasNext()) {
            String s = in.nextLine();
            for (char a : s.toCharArray())
                System.out.print(map.get(a));
            System.out.println("");
        }
    }
}
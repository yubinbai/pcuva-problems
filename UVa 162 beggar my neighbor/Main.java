import java.io.PrintWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            while (line.equals(""))
                line = sc.nextLine();
            if (line.equals("#"))
                break;
            gameOver = false;
            Player[] players = new Player[2];
            for (int i = 0; i < players.length; i++) {
                players[i] = new Player();
            }
            Card[] deck = new Card[52];
            StringTokenizer st = new StringTokenizer(line);
            for (int i = 0; i < 13; i++) {
                deck[i] = new Card(st.nextToken());
            }
            for (int i = 13; i < 52; i++) {
                deck[i] = new Card(sc.next());
            }
            for (int j = 0; j < players.length; j++) {
                for (int i = 0; i < 26; i++) {
                    players[j].deck.add(deck[i * 2 + j]);
                }
                Collections.reverse(players[j].deck);
            }
            // players[0] = non-dealer
            // players[1] = dealer
            int idx = 0;
            LinkedList<Card> stack = new LinkedList<Card>();
            while ((players[0].deck.size() > 0 || players[1].deck.size() > 0) && !gameOver) {
                Card played = players[idx].deck.poll();
                if (played == null)
                    break;
                stack.add(played);
                if (played.isFaceCard()) {
                    idx = doThing(stack, players, idx);
                }
                idx = 1 - idx;
            }
            if (players[0].deck.isEmpty()) {
                out.println("1 " + String.format("%2d", players[1].deck.size()));
            } else {
                out.println("2 " + String.format("%2d", players[0].deck.size()));
            }
        }
        out.close();
        sc.close();
    }
    private static boolean gameOver = false;
    private static int doThing(LinkedList<Card> stack, Player[] players, int idx) {
        boolean good = true;
        idx = 1 - idx;
        int val = getGameCardVal(stack.peekLast());
        for (int i = 0; i < val; i++) {
            Card played = players[idx].deck.poll();
            if (played == null) {
                gameOver = true;
                good = false;
                break;
            } else {
                stack.add(played);
                if (played.isFaceCard()) {
                    return doThing(stack, players, idx);
                }
            }
        }
        if (good)
            while (!stack.isEmpty()) {
                players[1 - idx].deck.add(stack.poll());
            }
        return idx;
    }
    private static int getGameCardVal(Card c) {
        switch (c.card.charAt(1)) {
        case 'A':
            return 4;
        case 'K':
            return 3;
        case 'Q':
            return 2;
        case 'J':
            return 1;
        }
        return 0;
    }
    private static class Card {
        String card;
        public Card(String card) {
            int test1 = getSuitIdx(card.charAt(0));
            if (test1 == -1)
                return;
            int test2 = getNumIdx(card.charAt(1));
            if (test2 == -1)
                return;
            this.card = card;
        }
        public boolean isFaceCard() {
            int val = getCardValue();
            return (val == 1 || val == 11 || val == 12 || val == 13);
        }
        public int getCardValue() {
            return getNumIdx(card.charAt(1));
        }
        private int getSuitIdx(char suit) {
            switch (suit) {
            case 'H':
                return 0;
            case 'S':
                return 1;
            case 'D':
                return 2;
            case 'C':
                return 3;
            }
            return -1;
        }
        private int getNumIdx(char num) {
            switch (num) {
            case 'A':
                return 1;
            case 'T':
                return 10;
            case 'J':
                return 11;
            case 'Q':
                return 12;
            case 'K':
                return 13;
            default:
                try {
                    int val = Integer.parseInt(num + "");
                    if (val > 1 && val < 10)
                        return val;
                    return -1;
                } catch (Exception e) {
                    return -1;
                }
            }
        }
        @Override
        public String toString() {
            return this.card;
        }
    }
    private static class Player {
        private LinkedList<Card> deck;
        public Player() {
            deck = new LinkedList<Card>();
        }
        @Override
        public String toString() {
            return this.deck.toString();
        }
    }
}

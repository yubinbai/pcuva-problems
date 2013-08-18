import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import static java.lang.Math.*;

public class Main {
    public static final String BLACK_WINS = "Black wins.";
    public static final String WHITE_WINS = "White wins.";
    public static final String TIE = "Tie.";

    static class Card implements Comparable< Card > {
        final static String values = "23456789TJQKA";
        final static String suits = "CDHS";

        private int rank;
        private int value;
        private char suit;

        /**
         * Returns numeric representation of this card.
         * An integer number in range 0-51.
         */
        public int getRank() {
            return rank;
        }

        /**
         * Returns numeric value of this card.
         * An integer number in range 0-12.
         */
        public int getValue() {
            return value;
        }

        /**
         * Returns suit of this card.
         */
        public char getSuit() {
            return suit;
        }

        public Card(String card) {
            rank = rankCard(card);
            value = rank / suits.length();
            suit = suits.charAt(rank % suits.length());
        }

        private int rankCard(String card) {
            char value = card.charAt(0);
            char suit = card.charAt(1);

            for (int i = 0; i < values.length(); i++) {
                if (values.charAt(i) == value) {
                    for (int j = 0; j < suits.length(); j++) {
                        if (suit == suits.charAt(j)) {
                            return (i * suits.length() + j);
                        }
                    }
                }
            }

            return -1;
        }

        public int compareTo(Card otherCard) {
            if (this.value > otherCard.getValue())
                return 1;
            else if (this.value < otherCard.getValue())
                return -1;
            else return 0;
        }

        @Override
        public boolean equals(Object other) {
            Card otherCard = (Card)other;
            return this.value == otherCard.getValue();
        }
    }

    static class Hand {

        public static final int PAIR = 300000;
        public static final int TWO_PAIRS = 600000;
        public static final int THREE_OF_KIND = 1200000;
        public static final int STRAIGHT = 2400000;
        public static final int FLUSH = 4800000;
        public static final int FULL_HOUSE = 9600000;
        public static final int FOUR_OF_KIND = 18200000;
        public static final int STRAIGHT_FLUSH = 36400000;

        Card[] hand;
        int rank = Integer.MIN_VALUE;

        public Hand(String handString) {
            hand = new Card[5];
            String[] cards = handString.split(" ");
            for (int i = 0; i < 5; i++) {
                hand[i] = new Card(cards[i]);
            }
            Arrays.sort(hand);
        }

        /**
         * Returns true if hand contains five cards with consecutive values
         */
        public boolean isStraight() {
            return (hand[4].getValue() - hand[0].getValue() == 4);
        }

        /**
         * Returns Straight rank of this hand.
         * Hand is ranked by the highest card.
         */
        private int rankStraight() {
            return STRAIGHT + hand[4].getValue();
        }

        /**
         * Returns true if hand contains five cards of the same suit
         */
        public boolean isFlush() {
            for (int i = 1; i < 5; i++) {
                if (hand[i].getSuit() != hand[i - 1].getSuit())
                    return false;
            }
            return true;
        }

        /**
         * Returns Flash rank of this hand.
         * Hand is ranked using the rules for High Card.
         */
        private int rankFlush() {
            return FLUSH + rankHighCard();
        }

        /**
         * Returns High Card rank of this hand.
         */
        private int rankHighCard() {
            return (int) (pow(hand[4].getValue(), 5) +
                          pow(hand[3].getValue(), 4) +
                          pow(hand[2].getValue(), 3) +
                          pow(hand[1].getValue(), 2) +
                          pow(hand[0].getValue(), 1));
        }

        /**
         * Returns true if five cards are of the same suit with consecutive values.
         */
        public boolean isStraightFlush() {
            return isFlush() && isStraight();
        }

        /**
         * Returns Straigh Flush rank of this hand.
         * Ranked by the highest card in the hand.
         */
        private int rankStraightFlush() {
            return STRAIGHT_FLUSH + hand[4].getValue();
        }

        /**
         * Returns true if three cards are of the same value with the remaining two cards forming a pair.
         */
        public boolean isFullHouse() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            return ((card1 == card2 && card2 != card3 && card3 == card5) ||
                    (card1 == card3 && card3 != card4 && card4 == card5));
        }

        /**
         * Returns Full House rank of this hand.
         * Ranked by the value of the three cards.
         */
        private int rankFullHouse() {
            int card1 = hand[0].getValue();
            int card3 = hand[2].getValue();
            int card5 = hand[4].getValue();

            int rank = FULL_HOUSE;
            if (card1 == card3) // three cards are in the lower part
                rank += card1;
            else if (card3 == card5) // three cards are in the upper part
                rank += card3;

            return rank;
        }

        /**
         * Returns true if four cards have the same value.
         */
        public boolean isFourOfKind() {
            return (hand[3].getValue() == hand[0].getValue() ||
                    hand[4].getValue() == hand[1].getValue());
        }

        /**
         * Ranks Four of Kind rank of this hand.
         * Ranked by the value of the four cards.
         */
        private int rankFourOfKind() {
            int rank = FOUR_OF_KIND;
            if (hand[3].getValue() == hand[0].getValue())
                rank += hand[3].getValue();
            else if (hand[4].getValue() == hand[1].getValue())
                rank += hand[4].getValue();
            return rank;
        }

        /**
         * Returns true if three of the cards in the hand have the same value.
         */
        public boolean isThreeOfKind() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            return (card1 == card3 || card2 == card4 || card3 == card5);
        }

        /**
         * Ranks Three of Kind rank of this hand.
         * Ranked by the value of the three cards.
         */
        private int rankThreeOfKind() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            int rank = THREE_OF_KIND;
            if (card1 == card3)
                rank += card1;
            else if (card2 == card4)
                rank += card2;
            else if (card3 == card5)
                rank += card3;

            return rank;
        }

        /**
         * Returns true if this hand contains two different pairs.
         */
        public boolean isTwoPairs() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            return ((card1 == card2 && card2 != card3 && card3 == card4 && card4 != card5) ||
                    (card1 != card2 && card2 == card3 && card3 != card4 && card4 == card5));
        }

        /**
         * Returns Two Pairs rank of this hand.
         * Ranked by the value of the highest pair or
         * by the next highest pair or
         * by the value of the remaining card.
         */
        private int rankTwoPairs() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            int pair1Val = Integer.MIN_VALUE;
            int pair2Val = Integer.MIN_VALUE;
            int remainVal = Integer.MIN_VALUE;

            if (card1 == card2 && card2 != card3 && card3 == card4 && card4 != card5) {
                pair1Val = card1;
                pair2Val = card3;
                remainVal = card5;
            } else if (card1 != card2 && card2 == card3 && card3 != card4 && card4 == card5) {
                pair1Val = card2;
                pair2Val = card4;
                remainVal = card1;
            }

            return TWO_PAIRS + (int) (pow(max(pair1Val, pair2Val), 3) + pow(min(pair1Val, pair2Val), 2) + remainVal);
        }

        /**
         * Returns true if two of the five cards in the hand have the same value.
         */
        public boolean isPair() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            return ((card1 == card2 && card2 != card3) || // cards 1 and 2 form pair
                    (card2 == card3 && card2 != card1 && card3 != card4) || // cards 2 and 3 form pair
                    (card3 == card4 && card3 != card2 && card4 != card5) || // cards 3 and 4 form pair
                    (card4 == card5 && card4 != card3)); // cards 4 and 5 form pair
        }

        /**
         * Ranked by the value of the cards forming the pair. If these values
         * are the same, the hands are ranked by the values of the cards
         * not forming the pair, in decreasing order
         */
        private int rankPair() {
            int card1 = hand[0].getValue();
            int card2 = hand[1].getValue();
            int card3 = hand[2].getValue();
            int card4 = hand[3].getValue();
            int card5 = hand[4].getValue();

            int rank = PAIR;

            if (card1 == card2 && card2 != card3) {
                rank += pow(card1, 4) + pow(card5, 3) + pow(card4, 2) + pow(card3, 1);
            } else if (card2 == card3 && card2 != card1 && card3 != card4) {
                rank += pow(card2, 4) + pow(card5, 3) + pow(card4, 2) + pow(card1, 1);
            } else if (card3 == card4 && card3 != card2 && card4 != card5) {
                rank += pow(card3, 4) + pow(card5, 3) + pow(card2, 2) + pow(card1, 1);
            } else if (card4 == card5 && card4 != card3) {
                rank += pow(card4, 4) + pow(card3, 3) + pow(card2, 2) + pow(card1, 1);
            }

            return rank;
        }

        /**
         * Returns a rank of this hand.
         * Rank is computed lazily.
         */
        public int getRank() {
            if (rank == Integer.MIN_VALUE) {
                // calculate rank
                if (isStraightFlush())
                    rank = rankStraightFlush();
                else if (isFourOfKind())
                    rank = rankFourOfKind();
                else if (isFullHouse())
                    rank = rankFullHouse();
                else if (isFlush())
                    rank = rankFlush();
                else if (isStraight())
                    rank = rankStraight();
                else if (isThreeOfKind())
                    rank = rankThreeOfKind();
                else if (isTwoPairs())
                    rank = rankTwoPairs();
                else if (isPair())
                    rank = rankPair();
                else
                    rank = rankHighCard();
            }
            return rank;
        }
    }

    public static void main( String[] args ) throws IOException {
        Main mainObj = new Main();

        final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = in.readLine()) != null) {
            System.out.println(mainObj.play(line));
        }
    }

    public  String play(String cardsString) {
        cardsString = cardsString.trim();
        String[] cards = cardsString.split(" ");
        StringBuilder blackHandString = new StringBuilder(), whiteHandString = new StringBuilder();

        for (int i = 0; i < 5; i++) {
            blackHandString.append(cards[i]);
            if (i != 4)
                blackHandString.append(" ");
        }
        for (int i = 5; i < 10; i++) {
            whiteHandString.append(cards[i]);
            if (i != 9)
                whiteHandString.append(" ");
        }

        Hand blackHand = new Hand(blackHandString.toString());
        Hand whiteHand = new Hand(whiteHandString.toString());

        int blackRank = blackHand.getRank();
        int whiteRank = whiteHand.getRank();

        if (blackRank > whiteRank)
            return BLACK_WINS;
        else if (whiteRank > blackRank)
            return WHITE_WINS;
        else return TIE;
    }
}
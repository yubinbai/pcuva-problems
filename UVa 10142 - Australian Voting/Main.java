import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static final String ELIMINATED = "eliminated";

    public static void main(String[] args) throws NumberFormatException, IOException {
        final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int numTestCases = Integer.parseInt(in.readLine());
        // read blank line
        in.readLine();

        for (int testCase = 1; testCase <= numTestCases; testCase++) {
            int numCandidates = Integer.parseInt(in.readLine());
            String[] candidates = new String[numCandidates];
            for (int candidate = 0; candidate < numCandidates; candidate++) {
                candidates[candidate] = in.readLine();
            }
            String line;
            List< int[] > ballots = new ArrayList< int[] >();
            while ((line = in.readLine()) != null && !line.equals("")) {
                int[] ballot = new int[numCandidates];
                StringTokenizer st = new StringTokenizer(line);
                int i = 0;
                while (st.hasMoreTokens()) {
                    ballot[i++] = Integer.parseInt(st.nextToken());
                }
                ballots.add(ballot);
            }

            String[] winners = getWinner(
                                   ballots.toArray(new int[ballots.size()][]),
                                   candidates);
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < winners.length; i++) {
                builder.append(winners[i]);
                if (i < winners.length - 1)
                    builder.append("\n");
            }

            if (testCase < numTestCases)
                builder.append("\n");

            System.out.println(builder.toString());
        }
    }

    static String[] getWinner(int[][] ballots, String[] candidates) {
        int[] tally = new int[candidates.length];

        // iterate until either a winner has been found or
        // all candidates have tied
        while (true) {
            int[] results = tallyResults(tally, ballots, candidates);
            int maxIndex = results[0];
            int minIndex = results[1];
            int maxVote = tally[maxIndex];
            int minVote = tally[minIndex];
            int totalVotes = ballots.length;

            if (maxVote == minVote) { // it is a tie
                // return the names of all non-eliminated candidates
                List< String > names = new ArrayList< String >();
                for (int i = 0; i < candidates.length; i++) {
                    if (!candidates[i].equals(ELIMINATED))
                        names.add(candidates[i]);
                }
                return names.toArray(new String[names.size()]);
            } else if (Math.round(((double)maxVote / totalVotes) * 100) > 50) {
                // see if maxVote exceeds 50% of all votes, if so, return the winner
                return new String[] { candidates[maxIndex] };
            }

            // eliminate candidates tied for the lowest number of votes
            for (int i = 0; i < candidates.length; i++) {
                if (tally[i] == minVote)
                    candidates[i] = ELIMINATED;
            }
        }
    }

    /**
     * Calculates statistics for the first choice candidates
     * and returns indices of candidates with MAX and MIN votes.
     * Runs in O(N) time where N is the total number of ballots (up to 1000).
     */
    static int[] tallyResults(int[] tally, int[][] ballots, String[] candidates) {
        resetTally(tally);

        for (int row = 0; row < ballots.length; row++) {
            tally[getIndex(ballots[row], candidates)]  += 1;
        }

        int maxIndex = Integer.MIN_VALUE, minIndex = Integer.MIN_VALUE;
        for (int i = 0; i < candidates.length; i++) {
            if (!candidates[i].equals(ELIMINATED)) {
                if (maxIndex == Integer.MIN_VALUE && minIndex == Integer.MIN_VALUE) {
                    maxIndex = i;
                    minIndex = i;
                } else {
                    if (tally[i] > tally[maxIndex])
                        maxIndex = i;
                    else if (tally[i] < tally[minIndex])
                        minIndex = i;
                }
            }
        }

        return new int[] {maxIndex, minIndex};
    }

    static int getIndex(int[] ballot, String[] candidates) {
        for (int i = 0; i < ballot.length; i++) {
            if (!candidates[ballot[i] - 1].equals(ELIMINATED))
                return ballot[i] - 1;
        }
        return -1;
    }

    static void resetTally(int[] tally) {
        for (int i = 0; i < tally.length; i++)
            tally[i] = 0;
    }
}
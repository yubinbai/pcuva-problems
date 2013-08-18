import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int calculateAmountToExchange(int[] expenses) {
        int amountToExchange = 0; // amount in cents
        int numberOfStudents = expenses.length;

        // calculate the average expense
        long averageExpense = 0; // in cents
        long totalExpenses = 0; // in cents
        for (double expense : expenses)
            totalExpenses += expense;

        averageExpense = Math.round((double) totalExpenses / numberOfStudents);
        int totalReceived = 0, totalGiven = 0;
        for (int i = 0; i < numberOfStudents; i++) {
            long diff = expenses[i] - averageExpense;
            if (diff > 0)
                totalReceived += diff;
            else
                totalGiven -= diff;
        }

        amountToExchange = totalReceived < totalGiven ? totalReceived : totalGiven;

        return amountToExchange;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader in = new BufferedReader(new InputStreamReader(
                    System.in));
        String line;
        int numberOfStudents = 0;
        int[] expenses = null; // expenses in cents

        while ((line = in.readLine()) != null) {
            try {
                numberOfStudents = Integer.parseInt(line);
            } catch (NumberFormatException e) {
                numberOfStudents = 0;
            }
            if (numberOfStudents == 0)
                return; // stop reading when 0 is found in input

            expenses = new int[numberOfStudents];
            for (int i = 0; i < numberOfStudents; i++) {
                line = in.readLine();
                float value = Float.parseFloat(line) * 100;
                expenses[i] = Math.round(value);
            }

            int amount = calculateAmountToExchange(expenses);
            System.out.print("$" + amount / 100 + ".");
            if (amount % 100 < 10)
                System.out.print("0");
            System.out.println(amount % 100);
        }
    }
}
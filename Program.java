import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the date: ");
        int date = sc.nextInt();
        System.out.print("Enter the month: ");
        int month = sc.nextInt();
        System.out.print("Enter the year: ");
        int year = sc.nextInt();

        // Zeller's Congruence
        int originalMonth = month;
        int originalYear = year;

        if (month < 3) {
            month += 12;
            year -= 1;
        }

        int k = year % 100;
        int j = year / 100;

        int h = (date + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;

        String day = "";
        switch (h) {
            case 0: day = "Saturday"; break;
            case 1: day = "Sunday"; break;
            case 2: day = "Monday"; break;
            case 3: day = "Tuesday"; break;
            case 4: day = "Wednesday"; break;
            case 5: day = "Thursday"; break;
            case 6: day = "Friday"; break;
        }

        System.out.println("The day on " + date + "/" + originalMonth + "/" + originalYear + " is " + day);

        sc.close();
    }
}

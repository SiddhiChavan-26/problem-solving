import java.util.*;

public class ArraysCC {
    public static void update(int numbers[] , int nonChangable){
        nonChangable = 10;
        for(int i = 0; i < numbers.length; i++){
            numbers[i] = numbers[i] + 1;
        }
        
    }
    public static void main(String[] args){
        int marks[] = new int[50];

        Scanner sc = new Scanner(System.in);

        marks[0] = sc.nextInt();
        marks[1] = sc.nextInt();
        marks[2] = sc.nextInt();

        System.out.println("Physics : " + marks[0]);
        System.out.println("Chemistry : " + marks[1]);
        System.out.println("Maths : " + marks[2]);

        int percentage = (marks[0] + marks[1] + marks[2]) / 3;
        System.out.println("Percentage : " + percentage + "%");
        System.out.println("Length of array : "+ marks.length);

        int numbers[] = {100, 200, 300};
        int nonChangable = 5;
        update(numbers, nonChangable);
        System.out.println();

        //print our number array
        System.out.println("Number array : ");
        for(int i = 0; i < numbers.length; i++){
            System.out.println("Numbers[i] : " + numbers[i]);
        }
    }
}

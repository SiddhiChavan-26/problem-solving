import java.util.*;

public class LargestSmallestNumbers {
    public static int largestNumber(int num[]){
        int largest = Integer.MIN_VALUE;

        for(int i = 0; i < num.length; i++){
            if(num[i] > largest){
                largest = num[i];
            }
        }
        return largest;
    }

    public static int smallestNumber(int num[]){
        int smallest = Integer.MAX_VALUE;
        for(int i = 0; i < num.length; i++){
            if(num[i] < smallest){
                smallest = num[i];
            }
        }
        return smallest;
    }
    public static void main(String[] args){
        int num[] = new int[5];

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter array elements: ");
        for(int i = 0; i < num.length; i++){
            num[i] = sc.nextInt();
        }

        int large = largestNumber(num);
        System.out.println("Largest number is : " + large);
        int small = smallestNumber(num);
        System.out.println("Smallest number is : " + small);
    }
}

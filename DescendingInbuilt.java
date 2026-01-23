import java.util.Arrays;
import java.util.Collections;

public class DescendingInbuilt{

    public static void printArray(Integer arr[]){
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }
    public static void main(String[] args){
        Integer arr[] = {10, 20, 50, 30, 40, 60};
        Integer arr1[] = {1, 2, 4, 6, 5};

        System.out.println("Arr1 sorted : ");
        Arrays.sort(arr, Collections.reverseOrder());
        printArray(arr);

        System.out.println("Arr1 sorted : ");
        Arrays.sort(arr1, 2, 5,Collections.reverseOrder());
        printArray(arr1);
    }
}

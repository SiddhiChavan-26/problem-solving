import java.util.Arrays;


public class AscendingInbuilt{

    public static void printArray(int arr[]){
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }
    public static void main(String[] args){
        int arr[] = {5, 4, 1, 3 , 2};
        int arr1[] = {5, 4, 9, 1, 8};

        System.out.println("Arr sorted : ");
        Arrays.sort(arr);
        printArray(arr);

        System.out.println("Arr1 sorted : ");
        Arrays.sort(arr1,2, 5 );
        printArray(arr1);
    }
}
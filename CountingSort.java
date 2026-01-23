public class CountingSort {

    public static void countingSort(int arr[]){
        int largest = Integer.MIN_VALUE;

        //find largest element in array
        for(int i = 0; i < arr.length; i++){
            largest = Math.max(largest, arr[i]);
        }

        //store freq of each ele in arr into new array count
        int count[] = new int[largest + 1];
        for(int i = 0; i <  arr.length ; i++){
            int num = arr[i];
            count[num]++;
        }

        //store in ascending order
        int j = 0;
        for(int i = 0; i < count.length; i++){
            while(count[i] > 0){
                arr[j] = i;
                j++;
                count[i]--;
            }
        }
    }

    public static void printArray(int arr[]){
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }
    public static void main(String[] args) {
        int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};

        countingSort(arr);
        printArray(arr);
    }
}

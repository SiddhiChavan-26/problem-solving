public class TransposeMatrix {
    
    public static void transpose(int nums[][], int newArr[][]){

        for(int i = 0; i < nums.length; i++){
            for(int j = 0; j < nums[0].length; j++){

                newArr[j][i] = nums[i][j];
            }
        }

        System.out.println("Transposed matrix : ");
        for(int i = 0; i < newArr.length; i++){
            for(int j = 0; j < newArr[0].length; j++){
                System.out.print(newArr[i][j] + " ");
            }
            System.out.println();
        }

    }
    public static void main(String[] args) {
        int nums[][] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        
        int row = nums[0].length;
        int col = nums.length;

        int newArr[][] = new int[row][col];
        transpose(nums, newArr);
    }
}

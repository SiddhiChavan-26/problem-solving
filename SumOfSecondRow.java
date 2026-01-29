public class SumOfSecondRow {
    public static int sumOfSecondRow(int matrix[][]){
        int sum = 0;
        int row = 1;
        for(int j = 0; j < matrix[0].length; j++){
            sum +=  matrix[row][j];
        }
        return sum;
    }
    public static void main(String[] args) {
        int matrix[][]= {
            {1, 4, 9},
            {11, 4, 3},
            {2, 2, 3}
        };

        System.out.println("The sum of elements in the second row is : "+ sumOfSecondRow(matrix));
    }
}

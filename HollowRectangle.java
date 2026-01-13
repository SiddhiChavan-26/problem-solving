public class HollowRectangle {
    public static void main(String[] args){
        int totRows = 4;
        int totCols = 5;

        //outer loop for lines
        for(int i = 1; i <= totRows; i++){
            //inner loop for the columns
            for(int j = 1; j <= totCols; j++){

                //boundary condition to print * only at boundary
                if(i == 1 || i == totRows || j == 1 || j == totCols){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }

            }
            System.out.println();
        }
    }
}

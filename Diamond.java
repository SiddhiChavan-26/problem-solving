public class Diamond {
    public static void main(String[] args){
        int n = 4;
        //first half
        for(int i = 1; i <= n; i++){
            //Spaces - (n - i)
            for(int j = 1; j <= (n-i); j++){
                System.out.print(" ");
            }

            //Star - (2*i - 1)
            for(int j = 1; j <= (2*i-1); j++){
                System.out.print("*");
            }
            System.out.println();
        }

        //second half
        for(int i = n; i >= 1; i--){
            //Spaces - (n-i)
            for(int j = 1; j <= (n - i); j++){
                System.out.print(" ");
            }

            //Star - (2*i-1)
            for(int j = 1; j <= (2*i-1); j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}

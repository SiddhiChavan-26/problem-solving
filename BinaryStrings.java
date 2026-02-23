public class BinaryStrings {
    public static void printBinString(int n , int lastPlace, String str){
        //base case 
        if(n == 0 ){
            System.out.println(str);
            return;
        }
        printBinString(n - 1 , 0, str+"0");
        if(lastPlace == 0){
            printBinString(n - 1, 1, str+"1");
        }
    }
    public static void main(String[] args){
        String str = new String ("");
        printBinString(3, 0, str);
    }
}

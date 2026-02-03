public class EvenOrOdd {
    public static void evenOdd(int n){
        int bitMask = 1;
        if((n & bitMask) == 0){
            System.out.println("Even Number");
        }else{
            System.out.println("Odd Number");
        }
    }
    public static void main(String[] args) {
        evenOdd(15);
        evenOdd(26);
    }
}

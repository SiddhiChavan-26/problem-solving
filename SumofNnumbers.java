
public class SumofNnumbers {
    public static int calcSum(int n){
        if(n == 1){
            return 1;
        }
        int s = n + calcSum(n-1);
        return s;
    }
    public static void main(String[] args) {
        int n = 5;
        System.out.println(calcSum(n));
    }
}



public class Power {
    public static int power (int x, int n){
        if( n == 0){
            return 1;
        }
        return x * power(x, n - 1);
    }

    public static int optimalPower(int x , int n){
        if(n == 0){
            return 1;
        }
        int halfPower = optimalPower(x, n/2);
        int halfPowerSq = halfPower * halfPower;

        if(n % 2 != 0){
            halfPowerSq = x * halfPowerSq;
        }
        return halfPowerSq;
    }
    public static void main(String[] args) {
        int x = 2, n = 5;
        System.out.println((power(2, 5)));
        System.out.println(optimalPower(x, n));
    }
}

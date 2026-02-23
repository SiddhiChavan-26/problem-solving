public class FriendsPairing {
    public static int fPairing(int n ){
        if(n == 1 || n == 2){
            return n;
        }
        //choice 
        //single 
        // int fnm1 = fPairing(n - 1);

        // //pair
        // int fnm2 = fPairing(n - 2);
        // int pairWays = (n - 1) * fnm2;

        // int totalWays = fnm1 + pairWays;
        // return totalWays;

        return fPairing(n - 1) + (n - 1) * fPairing(n - 2);
    }
    public static void main(String[] args){
        System.out.println(fPairing(6));
    }
}

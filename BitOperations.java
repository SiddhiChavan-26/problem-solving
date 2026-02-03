public class BitOperations {
    public static int getIthBit(int n, int i){
        int bitMask = 1 << i;
        if((n & bitMask) == 0){
            return 0;
        }else{
            return 1;
        }
    }

    public static int setIthBit(int n , int i){
        int bitMask = 1 << i;
        return n | bitMask;
    }

    public static int clearIthbit(int n , int i){
        int bitMask = ~(1 << i);
        return n & bitMask;
    }

    public static int updateIthBit(int n , int i, int newBit){
        if(newBit == 0){
            return clearIthbit(n, i);
        }else{
            return setIthBit(n, i);
        }
    }

    public static int clearIBits(int n, int i){
        int bitMask = (-1)<<i;
        return n & bitMask;
    }

    public static int clearBitRange(int n , int i, int j){
        int a = ((~0) << (j+1));
        int b = (1 << i) - 1;
        int bitMask = a | b;
        return n & bitMask;
    }

    public static void main(String[] args){
        System.out.println(getIthBit(15, 2)); 
        System.out.println(setIthBit(10, 2)); 
        System.out.println(clearIthbit(10, 1));  
        System.out.println(updateIthBit(10, 1, 0));   
        System.out.println(clearIBits(15,2)); 
        System.out.println(clearBitRange(10, 2, 4));
    }
}

package Recursion;

public class PrintNumbers{
    public static void printDesc(int n){
        if(n == 1){
            System.out.println(n);
            return;
        }
        System.out.println(n + " ");
        printDesc(n-1);
    }
    public static void printAsc(int n){
        if(n == 1){
            System.out.println(n);
            return;
        }
        printAsc(n-1);
        System.out.println(n + " ");
    }
    public static void main(String[] args){
        int n = 10;
        printDesc(n);
        printAsc(n);
    }
}

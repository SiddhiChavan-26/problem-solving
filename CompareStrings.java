public class CompareStrings {
    public static void main(String[] args){
        String str1 = "Tony"; 
        String str2 = "Tony"; //both str1 and str2 are pointing to the same location on the heap 
        String str3 = new String("Tony");//this creates a new object tony

        if(str1 == str2){
            System.out.println("str1 and str2 are equal");
        }else{
            System.out.println("str1 and str2 are not equal");
        }

        System.out.println("Without using .equals() method -->");
        if(str1 == str3){
            System.out.println("str1 and str3 are equal");
        }else{
            System.out.println("str1 and str3 are not equal");
        }

        System.out.println("Using .equals() method -->");
        if(str1.equals(str3)){
            System.out.println("str1 and str3 are equal");
        }else{
            System.out.println("str1 and str3 are not equal");
        }
    }
}

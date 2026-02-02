import java.util.*;

public class Anagram {
    public static boolean isAnagram(String s1, String s2){
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();

        if(s1.length() == s2.length()){
            char[] s1CharArray = s1.toCharArray();
            char[] s2CharArray = s2.toCharArray();

            Arrays.sort(s1CharArray);
            Arrays.sort(s2CharArray);

            return Arrays.equals(s1CharArray, s2CharArray);
        }

        return false;
    }
    public static void main(String[] args){
        String str1 = "earth";
        String str2 = "heart";

        if(isAnagram(str1, str2)){
            System.out.println("The string is Anagram");
        }else{
            System.out.println("The string is not Anagram");
        }
    }
}

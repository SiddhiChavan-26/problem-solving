//Count how many times lowercase vowels occurred in a String entered by the user.
import java.util.*;

public class LowerCaseVowel{
    public static void main(String[] args){
        System.out.print("Enter a string : ");
        String str = new Scanner(System.in).next();

        int count = 0;

        for(int i = 0; i < str.length(); i++){
            char vowel = str.charAt(i);

            if(vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u'){
                count++;
            }
        }

        System.out.println("The count of the vowels is : " + count);

    }
}
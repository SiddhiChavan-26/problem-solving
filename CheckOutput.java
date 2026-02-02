public class CheckOutput {
    public static void main(String[] args){
        String str = "ShradhaDidi";
        String str1 = "ApnaCollege";
        String str2 = "ShradhaDidi";

        System.out.println(str.equals(str1) + " " + str.equals(str2));

        String newStr = "ApnaCollege".replace("l", "");
        System.out.println(newStr);
    }
}

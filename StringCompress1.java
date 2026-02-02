public class StringCompress1 {
    //using string
    public static String compressString(String str){
        String newStr = "";

        for(int i = 0; i < str.length(); i++){
            Integer count = 1;
            while(i < str.length() - 1 && str.charAt(i) == str.charAt(i + 1)){
                count++;
                i++;
            }

            newStr += str.charAt(i);
            if(count > 1){
                newStr += count.toString();
            }
        }
        return newStr;
    }

    //using StringBuilder
    public static StringBuilder compressStringBuilder(String str){
        StringBuilder sb = new StringBuilder(" ");

        for(int i = 0; i < str.length(); i++){
            Integer cnt = 1;

            while(i < str.length() - 1 && str.charAt(i) == str.charAt(i + 1)){
                cnt++;
                i++;
            }
            sb.append(str.charAt(i));
            if(cnt > 1){
                sb.append(cnt.toString());
            }
        }
        return sb;
    }

    public static void main(String[] args){
        String str = "aaabbcccdd";
        System.out.println("The new string is : " + compressString(str));

        //using StringBuilder
        System.out.println("The string using StringBuilder : " + compressStringBuilder(str));
    }
}

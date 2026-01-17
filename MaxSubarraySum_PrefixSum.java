public class MaxSubarraySum_PrefixSum {
    public static void maxSubarray(int numbers[]){
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        //calculate prefix array
        int prefix[] = new int [numbers.length];
        prefix[0] = numbers[0];

        for(int i = 1; i < prefix.length; i++){
            prefix[i] = prefix[i - 1] + numbers[i];
        }

        //use loop to calculate currSum
        for(int i = 0; i < numbers.length; i++){
            for(int j = 0; j < numbers.length; j++){

                currSum = i == 0 ? prefix[j] : prefix[j] - prefix[i - 1];

                if(currSum > maxSum){
                    maxSum = currSum;
                }
            }
        }
        System.out.println("Max Sum : "+ maxSum);
    }
    public static void main(String[] args){
        int numbers[] = {1, -2, 6, -1, 3};

        maxSubarray(numbers);
    }
}
//calculate prefix array 
//prefix[i] = prefix[i-1] + numbers[i]
//then loop 
//currSum = prefix[end] - prefix[start - 1]
//compare with maxSum and then decide maxSum
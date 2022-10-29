// Link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class l_2136_Earliest_Possible_Day_of_Full_Bloom {
    public int earliestFullBloom(int[] plantTime, int[] growTime){
        int n = plantTime.length;
        int[] bloomTime = new int[n];
        for(int i = 0; i < n; i++){
            bloomTime[i] = plantTime[i] + growTime[i];
        }
        int left = 1, right = 1000000000;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(canBloom(bloomTime, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean canBloom(int[] bloomTime, int day){
        int n = bloomTime.length;
        int[] bloom = new int[n];
        for(int i = 0; i < n; i++){
            if(bloomTime[i] <= day){
                bloom[i] = 1;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(bloom[i] == 1){
                count++;
            }else{
                count = 0;
            }
            if(count == 3){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        l_2136_Earliest_Possible_Day_of_Full_Bloom solution = new l_2136_Earliest_Possible_Day_of_Full_Bloom();
        int[] plantTime = {1,4,3};
        int[] growTime = {2, 3, 1};
        System.out.println(solution.earliestFullBloom(plantTime, growTime));
    }
}
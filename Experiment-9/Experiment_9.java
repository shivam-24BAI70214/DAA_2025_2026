class Solution {
    public int minDifference(int arr[]) {
        int totSum=0;
        for (int num : arr){
            totSum+=num;
        }
        boolean[] dp=new boolean[totSum+1];
        dp[0]=true;
        for(int num : arr){
            for(int j=totSum;j>=num;j--){
                dp[j]=dp[j] || dp[j-num];
            }
        }
        int minDif=Integer.MAX_VALUE;

        for(int j=0;j<=totSum/2;j++){
            if(dp[j]){
                minDif=Math.min(minDif,totSum-2*j);
            }
        }
        return minDif;
    }
}

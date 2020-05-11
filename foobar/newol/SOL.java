
public class Solution {
    // public static int ans;
    public static void print(String s) {
        System.out.print(s);
    }

    public static int[][] dp;

    public static int rec(int n, int prevDigit) {
        if(n<0)
            return 0;
        if(0 == n)
            return 1;
        if(prevDigit+1 > n)
            return 0;
        if(dp[n][prevDigit] != -1) {
            return dp[n][prevDigit];
        }
        int ans = 0;
        for(int i=prevDigit+1;i<=n;i++) {
            ans += rec(n-i,i);
        }
        return dp[n][prevDigit] = ans;
    }
    public static int solution(int n) {
        // Your code here
        int ans = 0;
        dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++) {
                dp[i][j] = -1;
            }
        }
        for(int i=1;i<=Math.ceil(n/2.0);i++) {
            ans+=rec(n-i,i);
        }
        return ans;
    }
    public static void main(String args[]) {    
        String name = System.console().readLine();
        int x = Integer.parseInt(name);
        print(solution(x)+"\n");
    }
}

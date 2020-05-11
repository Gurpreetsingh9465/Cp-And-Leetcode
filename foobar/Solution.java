
public class Solution {
    // public static int ans;
    public static void print(String s) {
        System.out.print(s);
    }

    public static int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }

    public static float lcm(int a, int b) {
        return (float)a*b/(float)gcd(a,b);
    }

    public static int[] solution(int[][] m) {
        // Your code here
    }

    public static void main(String args[]) {    
        String name = System.console().readLine();
        // int x = Integer.parseInt(name);
        // print(solution(x)+"\n");
    }
}

import java.math.BigInteger;

public class Solution {

    public static boolean notPossible;
    
    public static void print(String s) {
        System.out.print(s);
    }

    public static BigInteger sol(BigInteger x, BigInteger y) {
        if(x.equals(new BigInteger("1"))) {
            return y.subtract(new BigInteger("1"));
        }
        if(y.equals(new BigInteger("1"))) {
            return x.subtract(new BigInteger("1"));
        }
        if(x.compareTo(new BigInteger("1")) == -1 || y.compareTo(new BigInteger("1")) == -1) {
            notPossible = true;
            return new BigInteger("-1");
        }
        if(x.equals(y)) {
            notPossible = true;
            return new BigInteger("-1");
        }
        if(x.compareTo(y) == -1) {
            BigInteger temp = x;
            x = y;
            y = temp;
        }
        if(x.compareTo(y.multiply(new BigInteger("1000"))) == 1) {
            BigInteger count = x.divide(y);
            x = x.subtract(count.multiply(y));
            return sol(x,y).add(count);
        }
        return sol(y,x.subtract(y)).add(new BigInteger("1"));
    }

    public static String solution(String x, String y) {
        notPossible = false;
        if(x.equals("1") && y.equals("1")) {
            return "0";
        }
        if(x.equals(y)) {
            return "impossible";
        }
        int lastX = Integer.parseInt(x.substring(x.length()-1));
        int lasty = Integer.parseInt(y.substring(y.length()-1));
        if((lastX%2==0) && (lasty%2==0)) {
            return "impossible";
        }
        if(x.equals("2")) {
            int val = (int)Math.ceil((Float.parseFloat(y)/2.0));
            return Integer.toString(val);
        }
        if(y.equals("2")) {
            int val = (int)Math.ceil((Float.parseFloat(x)/2.0));
            return Integer.toString(val);
        }
        BigInteger ans = sol(new BigInteger(x), new BigInteger(y));
        if(notPossible) {
            return "impossible";
        }
        return ans.toString();
    }
   public static void main(String args[]) {
       String name = System.console().readLine();
       String x = name.split(" ")[0];
       String y = name.split(" ")[1];
        print(solution(x,y)+"\n");
   }
}

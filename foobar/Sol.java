
public class Sol {

    public static int max_number_taken = -1;
    public static int[] freqNew;
    public static boolean[] index_taken;

    public static int getNumber(int[] l, boolean[] i_t) {
        String number = "";
        if(i_t!=null) {
            for(int i=0;i<i_t.length;i++) {
                if(i_t[i]) {
                    number+=l[i];
                }
            }
        }
        if(number == "")
            return 0;
        return Integer.parseInt(number);
    }

    public static boolean rec(int i, int[] l, int curSum, int taken,boolean[] recUSed) {
        if(i >= l.length) {
            if(curSum%3 == 0) {
                if(max_number_taken <= taken) {
                    max_number_taken = Math.max(max_number_taken, taken);
                    if(max_number_taken == taken) {
                        if(getNumber(l, index_taken) < getNumber(l, recUSed)) {
                            index_taken = recUSed;
                        }
                    } else {
                        index_taken = recUSed;
                    }
                }
                return true;
            }
            return false;
        }
        boolean[] newRecUsed = recUSed.clone();
        newRecUsed[i] = true;
        if(l[i]%3 == 0) {
            freqNew[l[i]]++;
            boolean right = rec(i+1,l,curSum+l[i],taken+1, newRecUsed);
            return right;
        }
        boolean left = rec(i+1,l,curSum+l[i],taken+1, newRecUsed);
        boolean right = rec(i+1,l,curSum,taken,recUSed);
        return left|right;
    }

    public static void print(String s) {
        System.out.print(s);
    }
    public static int solution(int[] l) {
        // Your code here
        int[] freq = new int[10];
        freqNew = new int[10];
        max_number_taken = -1;
        for(int i: l) {
            freq[i]++;
        }
        int index = 9;
        for(int i=0;i<=l.length;i++) {
            while(freq[index] == 0) {
                index--;
                if(index<0)
                    break;
            }
            if(index<0)
                break;
            freq[index]--;
            l[i] = index;
        }
        boolean[] recUsed = new boolean[l.length];
        for(int i=0;i<recUsed.length;i++) {
            recUsed[i] = false;
        }
        boolean ans = rec(0,l,0,0, recUsed);
        if(ans == false) {
            return 0;
        }
        return getNumber(l, index_taken);
    }

   public static void main(String args[]) {
       int[] a = {3, 1, 4, 1, 5, 9};
       try {
            System.out.println(solution(a));   
       } catch (Exception e) {
           e.printStackTrace();
       }
   }
}
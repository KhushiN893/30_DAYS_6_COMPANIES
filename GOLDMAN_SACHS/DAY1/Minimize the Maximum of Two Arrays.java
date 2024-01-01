class Solution {
    public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long lcm = lcm(divisor1, divisor2);
        int start = uniqueCnt1 + uniqueCnt2;
        int end = Integer.MAX_VALUE;
        while (start < end) {
            int mid = start + (end - start) / 2;
            boolean isUniqueCnt1 = (mid - mid / divisor1) >= uniqueCnt1;
            boolean isUniqueCnt2 = (mid - mid / divisor2) >= uniqueCnt2;
            boolean isUniqueCnt3 = (mid - mid / lcm) >= (uniqueCnt1 + uniqueCnt2);
            if (isUniqueCnt1 && isUniqueCnt2 && isUniqueCnt3) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    private long lcm(int a ,int b){
        return (a/gcd(a,b))*b;
       
    }
    private long gcd(int a,int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
}    

    
   

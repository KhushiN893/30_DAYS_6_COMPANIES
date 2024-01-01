class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = calculateLCM(divisor1, divisor2);
        int start = uniqueCnt1 + uniqueCnt2;
        int end = INT_MAX;
        while (start < end) {
            int mid = start + (end - start) / 2;
            bool isUniqueCnt1 = (mid - mid / divisor1) >= uniqueCnt1;
            bool isUniqueCnt2 = (mid - mid / divisor2) >= uniqueCnt2;
            bool isUniqueCnt3 = (mid - mid / lcm) >= (uniqueCnt1 + uniqueCnt2);
            if (isUniqueCnt1 && isUniqueCnt2 && isUniqueCnt3) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

private:
    long long calculateLCM(int a, int b) {
        return (a / calculateGCD(a, b)) * b;
    }

    long long calculateGCD(int a, int b) {
        if (a == 0) {
            return b;
        }
        return calculateGCD(b % a, a);
    }
};

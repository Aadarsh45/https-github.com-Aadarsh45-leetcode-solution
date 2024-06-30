class Solution {
    int check(int first,int second)
    {
        int parity = 1;
        int total = 0;
        while(first >= 0 && second >= 0)
        {
            if(parity % 2 == 1)
            {
                first = first - parity;
            }
            else
            {
                second = second - parity;
            }
            if(first < 0 || second < 0)
            {
                return total;
            }
            total++;
            parity++;
        }
        return total;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        int ans = max(check(red,blue), check(blue,red));
        return ans;
    }
};
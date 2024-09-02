class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int x1 = int(c1[0])-97;
        int y1 = int(c1[1])-49;

        int x2 = int(c2[0])-97;
        int y2 = int(c2[1])-49;
       
        if((x1+y1)%2 == (x2+y2)%2){
            return true;
        }
        return false; 
        
    }
};
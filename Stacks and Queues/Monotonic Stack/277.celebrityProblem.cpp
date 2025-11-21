/* The knows API is defined for you.
      bool knows(int a, int b); */
class Solution {
public:
    int findCelebrity(int n) {
        int top = 0, down = n-1;
        while(top < down) {
            if(knows(top, down)) {
                top = top + 1;
            }
            else if(knows(down, top)) {
                down = down - 1;
            }
            else {
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        for(int i=0; i < n; i++) {
            if(i == top) continue;
            if(knows(top, i) == 1 || knows(i, top) == 0) {
                return -1;
            }
        }
        return top;
    }
};
class Solution {
public:
    int minFlips(int a, int b, int c) {

        int minflips = 0;

        for(int i = 0; i < 32; i++){
            int a_bit = ((1 << i) & a) ? 1 : 0;
            int b_bit = ((1 << i) & b) ? 1 : 0;
            int c_bit = ((1 << i) & c) ? 1 : 0;


            if(c_bit == 1){
                if(a_bit == 0 && b_bit == 0){
                    minflips++;
                }
            }else{
                minflips += a_bit + b_bit;
            }
        }

        return minflips;
    }
};
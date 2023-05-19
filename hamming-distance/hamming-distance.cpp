class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> x_bits(x), y_bits(y);

        int hamming_distance = 0;
        for(int i = 0; i < 32; i++){
            if(x_bits[i] != y_bits[i]){
                hamming_distance++;
            }
        }


        return hamming_distance;
    }
};
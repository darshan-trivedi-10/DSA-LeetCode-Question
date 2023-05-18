class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        const int size = encoded.size();
        vector<int> decoded(size + 1);
        decoded[0]=(first);

        for(int i = 0; i < size; i++){
            decoded[i+1] = decoded[i] ^ encoded[i];
        }

        return decoded;

    }
};
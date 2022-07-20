int numMatchingSubseq(string s, vector<string>& words) {
int count = 0;
//Hashmap with string and bool pair
// Storing whether a string is subsequence or not!
map<string, bool> mp;
for(auto x: words){
//if the string has already occurred then don't compute again
if(mp.find(x) != mp.end()) {
// if that string has value true that means it is subsequence, count++
if(mp[x] == true) {
count++;
}
//if not, go for next string
continue;
}
// if not calculated previously, compute the value and assign to x(current string from words)
mp[x] = isSubsequence(s, x, s.size(), x.size());
count += (mp[x] == true);
}
// return the final count of number of subsequences.
return count;
}
};
```
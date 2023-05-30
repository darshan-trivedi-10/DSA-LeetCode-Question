class MyHashSet {
    vector<bool> isPresent;

public:
    MyHashSet() {
        isPresent.resize(1000010, false);
    }
    
    void add(int key) {
        isPresent[key] = true;
    }
    
    void remove(int key) {
        isPresent[key] = false;
    }
    
    bool contains(int key) {
        return isPresent[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
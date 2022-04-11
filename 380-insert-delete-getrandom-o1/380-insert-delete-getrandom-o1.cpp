class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        else{
            nums.push_back(val);
        m[val]=nums.size()-1;
        return true;
        }
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        else{
        int last = nums.back();
        nums[m[val]] = nums.back();  
        nums.pop_back();
        m[last]=m[val];
        m.erase(val);
        return true;
    }
    }
    
    int getRandom() {
        int sz = nums.size();
        if (sz == 0)    
            return -1;
        return nums[rand() % sz];
    }
    private:
       vector<int>nums;
       unordered_map<int,int>m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
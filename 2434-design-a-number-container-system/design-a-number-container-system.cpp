class NumberContainers {
public:
    unordered_map<int,int> m;
    unordered_map<int,set<int>>p;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m[index]!=number){
            int pval=m[index];
            auto it=p[pval].find(index);
            p[pval].erase(*it);
            m[index]=number;
        }
        p[number].insert(index);        
    }
    
    int find(int number) {
        if(p[number].size()==0) return -1;
        return *p[number].begin();
        
    }
};

//   if(this->m[number].size()==0) return -1;
//         return *this->m[number].begin();
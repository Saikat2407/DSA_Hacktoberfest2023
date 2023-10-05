class MyHashMap {
public:
    int table[1000001];
    MyHashMap() {
        memset(table, -1, sizeof(table));
    }
    
    void put(int key, int value) {
        table[key]=value;
    }
    
    int get(int key) {
        return table[key]==-1?-1:table[key];
    }
    
    void remove(int key) {
        table[key]=-1;
    }
};

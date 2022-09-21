class MyHashMap {
public:

    vector<list<pair<int,int>>> m;
    int size ;
    
    MyHashMap() {
        size = 1000;
        m.resize(size);
    }
    
    int hash(int key) {
        return (key%size);
    }
    
        list<pair<int,int>> :: iterator search(int key) 
    {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = m[i].begin();
        while(it != m[i].end()) {
            if(it->first == key) return it;
            it++;
        }
        return it;
    }

    // put(key , value) inserts the Value with it's corresponding Key

    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it == m[i].end()) return -1;
        return it->second;
    }

    void remove(int key)
    {
        int i = hash(key) ;

        // Before removing, we need to ensure that the key is present or not

        list<pair<int , int>> :: iterator it = search(key) ;

        // We only remove if the key is present

        if(it != m[i].end() )
            m[i].erase(it) ;
    }
};
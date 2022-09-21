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

    void put(int key, int value)
    {
        // We first calculate the index i using hash()

        int i = hash(key) ;

        // We first remove the key if it's present

        remove(key) ;

        // Otherwise, we insert the {key , value} pair inside the m[i] Doubly Linked List

        m[i].push_back({key , value}) ;
    }

    // get(key) function returns -1 if the key is not present, else returns the Value associated with the Key

    int get(int key)
    {
        int i = hash(key) ;

        // We first check whether the key is present or not using search() function

        list<pair<int , int>> :: iterator it = search(key) ;

        // If the iterator returned by search() is equal to m[i].end() , it implies the Key is not present, so we return -1

        if(it == m[i].end() )
            return -1 ;

        // Otherwise, we return the Value associated with the key using it -> second

        else
            return it -> second ;

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
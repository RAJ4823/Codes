// Link: https://leetcode.com/problems/lfu-cache

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: lfu-cache
 *  RUNTIME: 531 ms
 *  MEMORY: 186.9 MB
 *  DATE: 1-29-2023, 10:55:40 AM
 *
 */

// Solution:

class LFUCache {
public:
    int capacity, minFreq=0;
    unordered_map<int, pair<int,int>> cache;
    unordered_map<int, list<int>::iterator> location;
    unordered_map<int,list<int>> freqMap;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key) == 0)
            return -1;
        
        updateFrequency(key);         
        return cache[key].first;
    }
    
    void put(int key, int value) 
    {
        if(this->capacity <= 0) 
            return;

        // if key is already in cache
        if(cache.count(key))
        {
            updateFrequency(key);            
            cache[key].first = value; //update value in cache
        }
        else
        {
            if(cache.size() >= this->capacity)
            {
                // remove last-element in the least-frequent-list, from cache
                int lru = freqMap[minFreq].back();

                cache.erase(lru);
                location.erase(lru);
                freqMap[minFreq].pop_back();
            } 
            
            // insert value and initialize frequency
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            location[key] = freqMap[0].begin();
            
            minFreq=0;// reset min frequency
        }
    }

private:
    void updateFrequency(int key)
    {
        int freq = cache[key].second++;

        // remove from prev frequency list and append to updated frequency list
        freqMap[freq].erase(location[key]);
        freqMap[freq+1].push_front(key);
        //update list pointer to new list begin
        location[key] = freqMap[freq+1].begin();

        // remove empty lists incase minFrequency raises
        if(freqMap[minFreq].size() == 0) {
            freqMap.erase(minFreq);
            minFreq++;
        }
    }

};

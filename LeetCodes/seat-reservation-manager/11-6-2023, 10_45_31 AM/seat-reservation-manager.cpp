// Link: https://leetcode.com/problems/seat-reservation-manager

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: seat-reservation-manager
 *  RUNTIME: 498 ms
 *  MEMORY: 190.8 MB
 *  DATE: 11-6-2023, 10:45:31 AM
 *
 */

// Solution:

class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        for(int i=1; i<= n; i++)
            st.insert(i);
    }
    
    int reserve() {
        int seat = *st.begin();
        st.erase(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

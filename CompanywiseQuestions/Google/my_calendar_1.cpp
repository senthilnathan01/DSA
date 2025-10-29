/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

LINK: https://leetcode.com/problems/my-calendar-i/description/
*/
class MyCalendar {
public:
    map<int, int> calendar;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        // get the event after or at startTime
        auto next = calendar.lower_bound(startTime);

        // check for overlap with next interval
        if(next!=calendar.end() && next->first<endTime) return false;

        // check for overlap with prev interval
        if(next!=calendar.begin()){
            auto prevInter = prev(next);
            if(prevInter->second > startTime) return false;
        }

        calendar[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

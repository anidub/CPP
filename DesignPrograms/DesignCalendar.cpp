#include <iostream>
#include <set>
#include <string>
#include <shared_mutex>

using namespace std;

struct Event {
    int start_time;
    int end_time;
    string name;

    // Comparator for sorting events
    bool operator<(const Event& other) const {
        if (start_time != other.start_time) {
            return start_time < other.start_time;
        }
        if (end_time != other.end_time) {
            return end_time < other.end_time;
        }
        return name < other.name;
    }
};

class CalendarAPI {
private:
    set<Event> events;
    //mutable shared_mutex mutex;

public:
    // Add an event (takes an Event object)
    void addEvent(const Event& event) {
    	//unique_lock<shared_mutex> lock(mutex); // ensuring exclusive access.
    	if(event.end_time <= event.start_time) return;
        if (events.find(event) != events.end()) {
            cout << "Event with the same start time, end time, and name already exists.\n";
            return;
        }

        events.insert(event);
        cout << "Event '" << event.name << "' added successfully.\n";
    }

    // Delete an event by start time, end time, and name
    void deleteEvent(int start_time, int end_time, const string& name) {
    	//unique_lock<shared_mutex> lock(mutex); // ensuring exclusive access.
        Event event = {start_time, end_time, name};

        // Check if the event exists in the set
        auto it = events.find(event);
        if (it == events.end()) {
            cout << "Event not found.\n";
            return;
        }

        // Remove the event from the set
        events.erase(it);
        cout << "Event '" << name << "' deleted successfully.\n";
    }

    // List all events
    void listEvents() const {
    	//shared_lock<shared_mutex> lock(mutex); //enabling concurrent reads.
        if (events.empty()) {
            cout << "No events to display.\n";
            return;
        }

        cout << "Listing all events:\n";
        for (const auto& event : events) {
            cout << "Event: " << event.name
                 << ", Start Time: " << event.start_time
                 << ", End Time: " << event.end_time << "\n";
        }
    }
};
/*
int main() {
    CalendarAPI calendar;

    // Creating Event objects
    Event event1 = {10, 12, "Meeting"};
    Event event2 = {9, 11, "Workshop"};
    Event event3 = {10, 12, "Meeting"};  // Duplicate start time, end time, and name
    Event event4 = {10, 12, "Conference"};  // Same time but different name

    // Adding events
    calendar.addEvent(event1);
    calendar.addEvent(event2);
    calendar.addEvent(event3);  // This should not be added (duplicate)
    calendar.addEvent(event4);

    // Listing events
    calendar.listEvents();

    // Deleting an event by start time, end time, and name
    calendar.deleteEvent(10, 12, "Meeting");

    // Listing events after deletion
    calendar.listEvents();

    return 0;
}*/

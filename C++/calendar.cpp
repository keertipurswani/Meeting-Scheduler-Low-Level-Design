#include "Calendar.hpp"

Calendar::Calendar() {}

void Calendar::addMeeting(int day, int meetingID) {
    // Check if the day exists in the calendar, if not, create it
    if (dayMeetings.find(day) == dayMeetings.end()) {
        dayMeetings[day] = vector<int>();
    }

    // Add the meeting ID to the specified day
    dayMeetings[day].push_back(meetingID);
}

vector<int> Calendar::getMeetings(int day) const {
    if (dayMeetings.find(day) != dayMeetings.end()) {
        return dayMeetings.at(day);
    }
    return vector<int>(); // Return an empty vector if no meetings for the day
}

void Calendar::display(int day) {
    for(auto meetingId : dayMeetings[day]) {
        MeetingManager meetingMgr = MeetingManager::getInstance();
        Meeting* meeting = meetingMgr.getMeeting(meetingId);
        meeting->display();
    }
}

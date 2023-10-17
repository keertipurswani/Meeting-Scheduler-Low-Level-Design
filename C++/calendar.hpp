#pragma once
#include "common.hpp"
#include "meetingMgr.hpp"

class Calendar {
public:
    Calendar();

    void addMeeting(int day, int meetingID);

    vector<int> getMeetings(int day) const;

    void display(int day);

private:
    //day number, meeting ids
    unordered_map<int, vector<int>> dayMeetings;
};

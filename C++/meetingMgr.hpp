#pragma once
#include <string>
#include <map>
#include "meeting.hpp"


class MeetingManager {
public:
    static MeetingManager& getInstance();

    Meeting* getMeeting(int meetingId);
    void setMeeting(int meetingId, Meeting* meeting);

private:
    MeetingManager() {} // Private constructor to enforce Singleton pattern

    map<int, Meeting*> meetings;
};


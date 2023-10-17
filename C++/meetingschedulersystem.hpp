#pragma once
#include "meeting.hpp"
#include "user.hpp"

class MeetingSchedulerSystem {
public:
    static MeetingSchedulerSystem& getInstance();

    bool scheduleMeeting(Meeting& meeting);

private:
    MeetingSchedulerSystem() = default; // Private constructor to enforce singleton pattern
    MeetingSchedulerSystem(const MeetingSchedulerSystem&) = delete;
    MeetingSchedulerSystem& operator=(const MeetingSchedulerSystem&) = delete;

    bool canScheduleMeeting(const Meeting& meeting, const User& user);
};

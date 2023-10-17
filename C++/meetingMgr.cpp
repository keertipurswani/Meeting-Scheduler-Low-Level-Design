#include "meetingMgr.hpp"

MeetingManager& MeetingManager::getInstance() {
    static MeetingManager instance;
    return instance;
}

Meeting* MeetingManager::getMeeting(int meetingId) {
    auto it = meetings.find(meetingId);
    if (it != meetings.end()) {
        return it->second;
    }
    return nullptr;
}

void MeetingManager::setMeeting(int meetingId, Meeting* meeting) {
    meetings[meetingId] = meeting;
}

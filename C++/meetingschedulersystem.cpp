#include "meetingschedulersystem.hpp"
#include "meeting.hpp"
#include "meetingMgr.hpp"
#include "notificationMgr.hpp"

MeetingSchedulerSystem& MeetingSchedulerSystem::getInstance() {
    static MeetingSchedulerSystem instance;
    return instance;
}

bool MeetingSchedulerSystem::scheduleMeeting(Meeting& meeting) {
    // Check if the meeting can be scheduled
    User* organiser = meeting.getOrganiser();
    if (canScheduleMeeting(meeting, *organiser)) {
        // Meeting can be scheduled
        organiser->getCalendar().addMeeting(meeting.getDayOfMeeting(), meeting.getId());
        for(auto participant : meeting.getParticipants()) {
            participant->getCalendar().addMeeting(meeting.getDayOfMeeting(), meeting.getId());
        }
        //meeting is scheduled. inserting it in the meeting manager
        MeetingManager& manager = MeetingManager::getInstance();
        manager.setMeeting(meeting.getId(), &meeting);

        NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
        for(auto participant : meeting.getParticipants()) {
            notificationMgr->notify(participant->getName(), "Meeting scheduled");
        }
        return true;
    }
    else {
        // Meeting cannot be scheduled; suggest timings or update the meeting object
        meeting.setSuggestedTimings({ "10:00 AM", "2:00 PM", "4:30 PM" });

        return false;
    }
}

bool MeetingSchedulerSystem::canScheduleMeeting(const Meeting& meeting, const User& user) {
    // Implement your scheduling logic here
    // Check the user's calendar to see if the proposed meeting time conflicts with existing meetings

    // For simplicity, we'll assume that the meeting can always be scheduled
    return true;
}

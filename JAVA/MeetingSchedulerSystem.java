import java.util.ArrayList;
import java.util.List;

public class MeetingSchedulerSystem {
    private static final MeetingSchedulerSystem instance = new MeetingSchedulerSystem();

    private MeetingSchedulerSystem() {} // Private constructor to enforce singleton pattern

    public static MeetingSchedulerSystem getInstance() {
        return instance;
    }

    public boolean scheduleMeeting(Meeting meeting) {
        // Check if the meeting can be scheduled
        User creator = meeting.getOrganiser();
        if (canScheduleMeeting(meeting, creator)) {
            // Meeting can be scheduled
            creator.getCalendar().addMeeting(meeting.getDayOfMeeting(), meeting.getId());
            for (User participant : meeting.getParticipants()) {
                participant.getCalendar().addMeeting(meeting.getDayOfMeeting(), meeting.getId());
            }
            // Meeting is scheduled; insert it in the meeting manager
            MeetingManager manager = MeetingManager.getInstance();
            manager.setMeeting(meeting.getId(), meeting);

            NotificationMgr notificationMgr = NotificationMgr.getNotificationMgr();
            for (User participant : meeting.getParticipants()) {
                notificationMgr.notify(participant.getName(), "Meeting scheduled");
            }

            return true;
        } else {
            // Meeting cannot be scheduled; suggest timings or update the meeting object
            List<String> suggestedTimings = new ArrayList<>();
            suggestedTimings.add("10:00 AM");
            suggestedTimings.add("2:00 PM");
            suggestedTimings.add("4:30 PM");
            meeting.setSuggestedTimings(suggestedTimings);

            return false;
        }
    }

    private boolean canScheduleMeeting(Meeting meeting, User user) {
        // Implement your scheduling logic here
        // Check the user's calendar to see if the proposed meeting time conflicts with existing meetings

        // For simplicity, we'll assume that the meeting can always be scheduled
        return true;
    }
}

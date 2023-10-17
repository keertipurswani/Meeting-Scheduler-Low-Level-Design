import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Calendar {
    private Map<Integer, List<Integer>> dayMeetings;

    public Calendar() {
        dayMeetings = new HashMap<>();
    }

    public void addMeeting(int day, int meetingID) {
        // Check if the day exists in the calendar, if not, create it
        if (!dayMeetings.containsKey(day)) {
            dayMeetings.put(day, new ArrayList<>());
        }

        // Add the meeting ID to the specified day
        dayMeetings.get(day).add(meetingID);
    }

    public List<Integer> getMeetings(int day) {
        if (dayMeetings.containsKey(day)) {
            return dayMeetings.get(day);
        }
        return new ArrayList<>(); // Return an empty list if no meetings for the day
    }

    public void display(int day) {
        for (int meetingId : dayMeetings.get(day)) {
            MeetingManager meetingMgr = MeetingManager.getInstance();
            Meeting meeting = meetingMgr.getMeeting(meetingId);
            meeting.display();
        }
    }
}

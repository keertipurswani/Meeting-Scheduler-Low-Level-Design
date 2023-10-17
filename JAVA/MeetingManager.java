import java.util.HashMap;
import java.util.Map;

public class MeetingManager {
    private static final MeetingManager instance = new MeetingManager();
    private Map<Integer, Meeting> meetings = new HashMap<>();

    private MeetingManager() {} // Private constructor to enforce Singleton pattern

    public static MeetingManager getInstance() {
        return instance;
    }

    public Meeting getMeeting(int meetingId) {
        return meetings.get(meetingId);
    }

    public void setMeeting(int meetingId, Meeting meeting) {
        meetings.put(meetingId, meeting);
    }
}

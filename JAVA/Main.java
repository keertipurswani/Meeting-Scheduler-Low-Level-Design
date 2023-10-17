import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("Online meeting scheduler application started...");

        User organiser = new User(1001, "amit", "sde2");
        User rahul = new User(1002, "rahul", "fresher");
        User participant2 = new User(1003, "keerti", "manager");

        System.out.println("--------------------------------------------------");

        NotificationMgr notificationMgr = NotificationMgr.getNotificationMgr();

        notificationMgr.addNotificationSender(rahul.getName(), new SMSNotificationSender());
        notificationMgr.addNotificationSender(participant2.getName(), new PushNotificationSender());

        List<User> participants = new ArrayList<>();
        participants.add(rahul);
        participants.add(participant2);
        String subject = "low level system design discussion.";
        String title = "low level system design discussion.";
        String description = "low level system design discussion. will discuss in detail";
        int dayofmeeting = 289; // Right now, dayofmeeting represents a particular day since an epoch day. Let's consider epoch day for demo purposes as 1st January 2023. So dayofmeeting on 17th October will be (1st January 2023 - 17th October 2023) which is 289 days.
        String starttime = "12:30 pm"; // This could be represented in different time formats
        String endtime = "14:30 pm";
        boolean ismeetingrecurring = true;

        // Create a meeting and show details of the meeting
        Meeting meeting = new Meeting(101, organiser, "Discuss project details", "Project X", participants, dayofmeeting, starttime, endtime, ismeetingrecurring);

        MeetingSchedulerSystem instance = MeetingSchedulerSystem.getInstance();
        if (instance.scheduleMeeting(meeting)) {
            System.out.println("Meeting scheduled successfully");
        } else {
            List<String> suggestedtimings = meeting.getSuggestedTmings();
            System.out.println("Timings not available for the meeting. Suggested timings are: ");
            for (String timing : suggestedtimings) {
                System.out.print(timing + "  ");
            }
            System.out.println();
        }

        participant2.displayCalendar(289);
    }
}

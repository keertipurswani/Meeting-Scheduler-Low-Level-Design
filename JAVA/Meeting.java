import java.util.ArrayList;
import java.util.List;

public class Meeting {
    private int id;
    private User creator;
    private String description;
    private String subject;
    private List<User> participants;
    private int dayofmeeting;
    private String starttime;
    private String endtime;
    private boolean isRecurring;
    private List<String> suggestedTimings;

    public Meeting(int id, User creator, String description, String subject) {
        this.id = id;
        this.creator = creator;
        this.description = description;
        this.subject = subject;
        this.participants = new ArrayList<>();
    }

    public Meeting(int id, User creator, String description, String subject, List<User> participants) {
        this.id = id;
        this.creator = creator;
        this.description = description;
        this.subject = subject;
        this.participants = participants;
    }

    public Meeting(int id, User creator, String description, String subject, List<User> participants, int pdayofmeeting, String pstarttime, String pendtime, boolean pisrecurring) {
        this.id = id;
        this.creator = creator;
        this.description = description;
        this.subject = subject;
        this.participants = participants;
        this.dayofmeeting = pdayofmeeting;
        this.starttime = pstarttime;
        this.endtime = pendtime;
        this.isRecurring = pisrecurring;
        this.suggestedTimings = new ArrayList<>();
    }

    public void display() {
        System.out.println("------------------------------------------");
        System.out.println("Meeting details for meeting id " + id + " -");
        System.out.println("Subject - " + getSubject());
        System.out.println("Description - " + getDescription());
        System.out.println("Organiser - " + getOrganiser().getName());
        System.out.print("Participants - ");
        for (User user : participants) {
            System.out.print(user.getName() + " ");
        }
        System.out.println("\n------------------------------------------");
    }

    public int getId() {
        return id;
    }

    public User getOrganiser() {
        return creator;
    }

    public String getDescription() {
        return description;
    }

    public String getSubject() {
        return subject;
    }

    public int getDayOfMeeting() {
        return dayofmeeting;
    }

    public List<User> getParticipants() {
        return participants;
    }

    public List<String> getSuggestedTmings() {
        return suggestedTimings;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setCreator(User creator) {
        this.creator = creator;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public void setDayOfMeeting(int pdayofmeeting) {
        dayofmeeting = pdayofmeeting;
    }

    public void setStartTime(String pstarttime) {
        starttime = pstarttime;
    }

    public void setEndTime(String pendtime) {
        endtime = pendtime;
    }

    public void setIsRecurring(boolean pisrecurring) {
        isRecurring = pisrecurring;
    }

    public void setSuggestedTimings(List<String> psuggestedtimings) {
        suggestedTimings = psuggestedtimings;
    }
}

public class User {
    private int id;
    private String name;
    private String designation;
    private Calendar calendar;

    public User(int id, String name, String designation) {
        this.id = id;
        this.name = name;
        this.designation = designation;
        this.calendar = new Calendar();
    }

    public void displayCalendar(int day) {
        calendar.display(day);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getDesignation() {
        return designation;
    }

    public Calendar getCalendar() {
        return calendar;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }
}

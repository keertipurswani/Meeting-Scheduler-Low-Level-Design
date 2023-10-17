import java.util.HashMap;
import java.util.Map;

public class CalendarMgr {
    // User name to calendar mapping
    private Map<String, Calendar> calendars;

    public CalendarMgr() {
        calendars = new HashMap<>();
    }

    public Calendar getCalendarForUser(String userName) {
        // If the user has a calendar, return it; otherwise, create a new one and return it
        return calendars.computeIfAbsent(userName, key -> new Calendar());
    }
}

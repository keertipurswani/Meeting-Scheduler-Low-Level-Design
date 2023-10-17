#pragma once

class CalendarMgr{
        //user name, calendar
        unordered_map<string, Calendar> calendars;
    public:
        Calendar getCalendarForUser();
};
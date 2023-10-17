#pragma once
#include <string>
#include <vector>

using namespace std;

class User; // Forward declaration

class Meeting {
public:
    Meeting(int id, User* creator, const string& description, const string& subject);
    Meeting(int id, User* creator, const string& description, const string& subject, const vector<User*>& participants);

    Meeting(int id, User* creator, const string& description, const string& subject, const vector<User*>& participants,
        int pdayofmeeting, string pstarttime, string pendtime, bool pisrecurring);

    void display();

    // Getters
    int getId() const;
    User* getOrganiser() const;
    string getDescription() const;
    string getSubject() const;
    const vector<User*>& getParticipants() const;
    vector<string> getSuggestedTmings();
    int getDayOfMeeting() const;

    // Setters
    void setId(int id);
    void setCreator(User* creator);
    void setDescription(const string& description);
    void setSubject(const string& subject);

    void setDayOfMeeting(int pdayofmeeting);
    void setStartTime(string& pstarttime);
    void setEndTime(string& pendtime);

    void setIsRecurring(bool pisrecurring);

    void setSuggestedTimings(vector<string> psuggestedtimings);


private:
    int id;
    User* creator;
    string description;
    string subject;
    vector<User*> participants;
    int dayofmeeting;
    string starttime;
    string endtime;
    bool isRecurring;
    vector<string> suggestedTimings;
};

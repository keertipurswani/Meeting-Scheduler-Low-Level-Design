#include "Meeting.hpp"
#include "User.hpp"
#include <string>

using namespace std;

Meeting::Meeting(int id, User* creator, const string& description, const string& subject)
    : id(id), creator(creator), description(description), subject(subject) {}

Meeting::Meeting(int id, User* creator, const string& description, const string& subject, const vector<User*>& participants)
    : id(id), creator(creator), description(description), subject(subject), participants(participants) {}


Meeting::Meeting(int id, User* creator, const string& description, const string& subject, const vector<User*>& participants, int pdayofmeeting, string pstarttime, string pendtime, bool pisrecurring)
    : id(id), creator(creator), description(description), subject(subject), participants(participants), dayofmeeting(pdayofmeeting), starttime(pstarttime),
    endtime(pendtime){}

void Meeting::display() {
    cout<<endl<<"------------------------------------------"<<endl;
    cout<<"Meeting details for meeting id "<<id<<" -"<<endl;
    cout<<"Subject - "<<getSubject()<<endl;
    cout<<"Description - "<<getDescription()<<endl;
    cout<<"Organiser - "<<getOrganiser()->getName()<<endl;
    cout<<"Participants - ";
    for(auto user : participants) {
        cout<<user->getName()<<" ";
    }
    cout<<endl<<"------------------------------------------"<<endl;
}

int Meeting::getId() const {
    return id;
}

User* Meeting::getOrganiser() const {
    return creator;
}

string Meeting::getDescription() const {
    return description;
}

string Meeting::getSubject() const {
    return subject;
}

int Meeting::getDayOfMeeting() const {
    return dayofmeeting;
}

const vector<User*>& Meeting::getParticipants() const {
    return participants;
}

vector<string> Meeting::getSuggestedTmings() {
    return suggestedTimings;
}

void Meeting::setId(int id) {
    this->id = id;
}

void Meeting::setCreator(User* creator) {
    this->creator = creator;
}

void Meeting::setDescription(const string& description) {
    this->description = description;
}

void Meeting::setSubject(const string& subject) {
    this->subject = subject;
}

void Meeting::setDayOfMeeting(int pdayofmeeting) {
    dayofmeeting = pdayofmeeting;

}
void Meeting::setStartTime(string& pstarttime) {
    starttime = pstarttime;

}
void Meeting::setEndTime(string& pendtime) {
    endtime = pendtime;
}

void Meeting::setIsRecurring(bool pisrecurring) {
    isRecurring = pisrecurring;
}

void Meeting::setSuggestedTimings(vector<string> psuggestedtimings) {
    suggestedTimings = psuggestedtimings;
}



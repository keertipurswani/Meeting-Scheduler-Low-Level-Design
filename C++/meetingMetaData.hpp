#pragma once;
#include "user.hpp"

class MeetingMetaData
{
    User *organiser;
    vector<User *> participants;
    string subject;
    string description;
    string startTime;
    string endTime;

public:
    MeetingMetaData(User* organiser, vector<User *> participants, string startTime, string endTime, string subject, string description) : organiser(organiser), participants(participants), startTime(startTime), endTime(endTime), subject(subject), description(description) {}
    
    User *getOrganiser() const
    {
        return organiser;
    }

    void setOrganiser(User *newOrganiser)
    {
        organiser = newOrganiser;
    }

    vector<User *> getParticipants() const
    {
        return participants;
    }

    void addParticipant(User *participant)
    {
        participants.push_back(participant);
    }

    string getSubject() const
    {
        return subject;
    }

    void setSubject(const string &newSubject)
    {
        subject = newSubject;
    }

    string getDescription() const
    {
        return description;
    }

    void setDescription(const string &newDescription)
    {
        description = newDescription;
    }
};
#pragma once
#include <string>
#include "calendar.hpp"

class User {
public:
    User(int id, const string& name, const string& designation);

    // Getters
    int getId() const;
    string getName() const;
    string getDesignation() const;
    Calendar& getCalendar();

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setDesignation(const string& designation);

    void displayCalendar(int day);

private:
    int id;
    string name;
    string designation;
    Calendar calendar;
};

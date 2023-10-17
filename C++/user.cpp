#include "user.hpp"
#include <string>

using namespace std;

User::User(int id, const string& name, const string& designation)
    : id(id), name(name), designation(designation) {}

void User::displayCalendar(int day) {
    calendar.display(day);
}

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}

string User::getDesignation() const {
    return designation;
}

Calendar& User::getCalendar() {
    return calendar;
}

void User::setId(int id) {
    this->id = id;
}

void User::setName(const string& name) {
    this->name = name;
}

void User::setDesignation(const string& designation) {
    this->designation = designation;
}

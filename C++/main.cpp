#include "common.hpp"
#include "user.hpp"
#include "meeting.hpp"
#include "meetingschedulersystem.hpp"
#include "notificationMgr.hpp"
#include "smsNotificationSender.hpp"
#include "pushNotificationSender.hpp"

using namespace std;

int main() {
	cout << "Online meeting scheduler application started..." << endl;
	User* organiser = new User(1001, "amit", "sde2");
	User* rahul = new User(1002, "rahul", "fresher");
	User* participant2 = new User(1003, "keerti", "manager");

    cout<<"--------------------------------------------------"<<endl;

    NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();

    notificationMgr->addNotificationSender(rahul->getName(), new SMSNotificationSender());
    notificationMgr->addNotificationSender(participant2->getName(), new PushNotificationSender());

	vector<User*> participants = {rahul, participant2};
	string subject = "low level system design discussion.";
	string title = "low level system design discussion.";
	string description = "low level system design discussion.will discuss in details";
	int dayofmeeting = 289; /*right now dayofmeeting is basically represnting a particular day since a epoch day.lets consider epoch day for demo purpose as 1st January 2023. So dayofmeeting on 17th October will be (1st january 2023 - 17th october 2023) which is 289 days
		*/
	string starttime = "12.30 pm"; //this could be represented in differnt time formats
	string endtime = "14:30 pm";
	bool ismeetingrecurring = true;
	

	//create meeting and show details of the meeting
	Meeting meeting(101, organiser, "Discuss project details", "Project X", participants, dayofmeeting, starttime, endtime, ismeetingrecurring);

	MeetingSchedulerSystem& instance = MeetingSchedulerSystem::getInstance();
	if (instance.scheduleMeeting(meeting)) {
		cout<<"Meeting scheduled successfully"<<endl;
	}
	else {
		vector<string> suggestedtimings  = meeting.getSuggestedTmings();
		cout << "Timings not available for meeting . suggested timings are " << endl;
		for (auto iter : suggestedtimings) {
			cout << iter << "  ";
		}
		cout << endl;
	}

    participant2->displayCalendar(289);

	return 0;
}
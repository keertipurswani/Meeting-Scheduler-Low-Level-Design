#pragma once
#include "common.hpp"
#include "inotificationSender.hpp"
#include "unordered_map"
#include "vector"
#include "mutex"

// This class corresponds to subject in the observer design pattern
// NotificationSender is the observer interface

class NotificationMgr
{
    NotificationMgr() {}
    static NotificationMgr *notificationMgrInstance;
    static mutex mtx;
    unordered_map<string, vector<INotificationSender *>> notificationSendersMap;

public:
    static NotificationMgr *getNotificationMgr();

    // register observer
    void addNotificationSender(string pUserId, INotificationSender *pNotificationSender)
    {
        // add check if sender is already added
        // sender shouldn't be pushed multiple times
        notificationSendersMap[pUserId].push_back(pNotificationSender);
    }

    // unregister observer
    void removeNotificationSender(string pUserId, INotificationSender *pNotificationSender)
    {
        auto senderPos = find(notificationSendersMap[pUserId].begin(),
                              notificationSendersMap[pUserId].end(), pNotificationSender);
        if (senderPos != notificationSendersMap[pUserId].end())
        {
            notificationSendersMap[pUserId].erase(senderPos);
        }
    }

    // notify Observers
    void notify(string pUserId, string pMsg)
    {   
        for (auto sender : notificationSendersMap[pUserId])
            sender->sendNotification(pUserId, pMsg);
    }
};
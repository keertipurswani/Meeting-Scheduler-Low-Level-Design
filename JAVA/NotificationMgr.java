import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NotificationMgr {
    private Map<String, List<INotificationSender>> notificationSendersMap = new ConcurrentHashMap<>();
    private static NotificationMgr notificationMgrInstance = null;
    private static final Lock mtx = new ReentrantLock();

    private NotificationMgr() {
    }

    public static NotificationMgr getNotificationMgr() {
        if (notificationMgrInstance == null) {
            mtx.lock();
            if (notificationMgrInstance == null) {
                notificationMgrInstance = new NotificationMgr();
            }
            mtx.unlock();
        }
        return notificationMgrInstance;
    }

    // Register observer
    public void addNotificationSender(String userId, INotificationSender notificationSender) {
        notificationSendersMap
                .computeIfAbsent(userId, k -> new ArrayList<>())
                .add(notificationSender);
    }

    // Unregister observer
    public void removeNotificationSender(String userId, INotificationSender notificationSender) {
        List<INotificationSender> senders = notificationSendersMap.get(userId);
        if (senders != null) {
            senders.remove(notificationSender);
        }
    }

    // Notify Observers
    public void notify(String userId, String message) {
        List<INotificationSender> senders = notificationSendersMap.get(userId);
        if (senders != null) {
            for (INotificationSender sender : senders) {
                sender.sendNotification(userId, message);
            }
        }
    }
}

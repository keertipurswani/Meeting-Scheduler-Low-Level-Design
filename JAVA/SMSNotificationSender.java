public class SMSNotificationSender implements INotificationSender {
    @Override
    public void sendNotification(String pUserId, String pMsg) {
        System.out.println("SMS Notification for " + pUserId + " is " + pMsg);
    }
}

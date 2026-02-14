class Notification {
    public void sendNotification() {
        System.out.println("Email Notification");
    }
}

class TextNotification extends Notification {
    @Override
    public void sendNotification() {
        System.out.println("Text Notification");
    }
}
class WhatsappNotification extends Notification {
    @Override
    public void sendNotification() {
        System.out.println("Whats app notification");
    }
}

public class LiskovSubstitution {
    public static void main(String[] args) {
        //Notification notification = new Notification();
        //Notification notification = new TextNotification();
        Notification notification = new WhatsappNotification();
        notification.sendNotification();
    }
}

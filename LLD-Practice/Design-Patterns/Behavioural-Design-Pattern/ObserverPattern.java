import java.util.ArrayList;
import java.util.List;

interface Subscriber {
    void update(String videoTitle);
}



class EmailSubscriber implements Subscriber {

    private String email;

    public EmailSubscriber(String email) {
        this.email = email;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("Email sent to: " + email + " New Video Uploaded : " + videoTitle);
    }
    
}

class MobileSubscriber implements Subscriber {

    private String username;

    public MobileSubscriber(String username) {
        this.username = username;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("Notification sent to: " + username + " New Video Uploaded : " + videoTitle);
    }
    
}

interface Channel {
    void subscribe(Subscriber subscriber);
    void unsubscribe(Subscriber subscriber);
    void notifySubscribers(String videoTitle);
}

class YoutubeChannel implements Channel{

    private String channelName;
    private List<Subscriber> subscriberList = new ArrayList<>();

    public YoutubeChannel(String channelName) {
        this.channelName = channelName;
    }
    

    @Override
    public void subscribe(Subscriber subscriber) {
        subscriberList.add(subscriber);
    }

    @Override
    public void unsubscribe(Subscriber subscriber) {
        subscriberList.remove(subscriber);
    }

    @Override
    public void notifySubscribers(String videoTitle) {
        for(Subscriber subscriber : subscriberList) {
            subscriber.update(videoTitle);
        }
    }

    public void uploadNewVideo(String videoTitle) {
        System.out.println(channelName + " Uploaded : " + videoTitle);
        notifySubscribers(videoTitle);
    }
}


public class ObserverPattern {
    public static void main(String[] args) {
        YoutubeChannel youtubeChannel = new YoutubeChannel("TUF");
        youtubeChannel.subscribe(new EmailSubscriber("test@gmail.com"));
        youtubeChannel.subscribe(new MobileSubscriber("test"));
        youtubeChannel.uploadNewVideo("observer-video");
    }
}

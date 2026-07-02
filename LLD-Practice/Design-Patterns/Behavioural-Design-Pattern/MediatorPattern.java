import java.util.ArrayList;
import java.util.List;

interface Mediator {
    void join(User user);
    void broadcastUser(String message, User sender);
}

class CollaborativeDocument implements Mediator {

    private List<User> others = new ArrayList<>();

    @Override
    public void join(User user) {
       others.add(user);
    }

    @Override
    public void broadcastUser(String message, User sender) {
        for(User user : others) {
            if(user != sender) {
                user.receiveChange(message, sender);
            }
        }
    }

}


class User {
    private String name;
    private CollaborativeDocument collaborativeDocument;

    public User(String name, CollaborativeDocument collaborativeDocument) {
        this.name = name;
        this.collaborativeDocument = collaborativeDocument;
    }

    public void makeChange(String message) {
        System.out.println(name + " edited the document: " + message);
        collaborativeDocument.broadcastUser(message, this);
    }

    public void receiveChange(String message, User sender) {
        System.out.println(name + " saw change from " + sender.name + ": \"" + message + "\"");
    }
}



public class MediatorPattern {
    public static void main(String[] args) {
        
        CollaborativeDocument doc = new CollaborativeDocument();

        User alice = new User("Alice", doc);
        User bob = new User("Bob", doc);

        doc.join(alice);
        doc.join(bob);

        alice.makeChange("This is alice change for title");
        bob.makeChange("this is bobs change");
    }
}


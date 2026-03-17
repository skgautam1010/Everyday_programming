import java.util.HashMap;
import java.util.Map;

interface EmailTemplate extends Cloneable { 
    EmailTemplate clone();
    void setContent(String content);
    void send(String to);
}


class WelcomeEmail implements EmailTemplate {
    private String subject;
    private String content;

    public WelcomeEmail() {
        this.subject = "Welcome to TUF+";
        this.content = "Hi there! Thanks for joining us.";
    }

    @Override
    public EmailTemplate clone() {
        try {
            return (WelcomeEmail) super.clone();
        } catch (Exception e) {
            throw new RuntimeException("Clone Failed" , e);
        }
    }

    @Override
    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public void send(String to) {
        System.out.println("Sending to " + to + ": [" + subject + "] " + content);
    }

 }


class EmailTemplateRegistry {
    private static final Map<String, EmailTemplate> templates = new HashMap<>();

    static {
        templates.put("welcome", new WelcomeEmail());
    }

    public static EmailTemplate getTemplate(String type) {
        return templates.get(type).clone();
    }
}



public class PrototypePattern {
    public static void main(String[] args) {
        EmailTemplate welcomeEmail1 = EmailTemplateRegistry.getTemplate("welcome");
        welcomeEmail1.setContent("Hi Alice, welcome to TUF Premium!");
        welcomeEmail1.send("alice@example.com");

        EmailTemplate welcomeEmail2 = EmailTemplateRegistry.getTemplate("welcome");
        welcomeEmail2.setContent("Hi Bob, thanks for joining!");
        welcomeEmail2.send("bob@example.com");
    }
    
}

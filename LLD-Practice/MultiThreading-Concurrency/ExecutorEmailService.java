
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorEmailService {

    public static final ExecutorService executor = Executors.newFixedThreadPool(10);

    public static void sendEmail(String recipient) {
        executor.execute(() -> {
            System.out.println("Sending email to " + recipient + " on " + Thread.currentThread().getName());
            try {
                // Simulate dummy work (sending an email)
                Thread.sleep(1000);  // Simulate delay
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();  // Handle interruption
            }
            System.out.println("Email sent to " + recipient);
        });
    }
    public static void main(String[] args) {
        for(int i=1;i<=25;i++) {
            sendEmail("User" + i + "@gmail.com");
        }
        executor.shutdown();
    }
}

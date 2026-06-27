import java.util.concurrent.*;

class AccountSharing {
    private final Semaphore availableSemaphore;

    public AccountSharing(int maxLimit) {
        this.availableSemaphore = new Semaphore(maxLimit);
    }

    public boolean login(String user) {
        try {
            System.out.println(user + " is trying to login....");
            if(availableSemaphore.tryAcquire()) {
                System.out.println(user + " successfully logged in");
                return true;
            } else {
                System.out.println("too many user already present--device limit exceeded");
                return false;
            }
        } catch (Exception e) {
        } finally {
        }
        return false;
    }

    public void logout(String user) {
        System.out.println(user + " logging out.");
        availableSemaphore.release();
    }
}

public class Semaphores {
    public static void main(String[] args) {
        
    }
}

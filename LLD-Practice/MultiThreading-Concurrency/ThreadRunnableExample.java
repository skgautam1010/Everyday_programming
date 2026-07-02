
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;


class SmsRunnableThread implements Runnable {

    @Override
    public void run() {
        try {
            Thread.sleep(2000);
            System.out.println("SMS Sent Successfully");
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class EmailRunnableThread implements Runnable {

    @Override
    public void run() {
        try {
            Thread.sleep(3000);
            System.out.println("Email Sent Successfully");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    }
}

class ETACalculator implements Callable<String> {

    private final String location;

    public ETACalculator(String location) {
        this.location = location;
    }

    @Override
    public String call() throws Exception {
        System.out.println("ETA for Location: " + location);
        Thread.sleep(5000);
        return "ETA to " + location + " : 20 minutes";
    }
    
}

public class ThreadRunnableExample {
    public static void main(String[] args) throws ExecutionException {
        Thread smsThread = new Thread(new SmsRunnableThread());
        smsThread.start();
        System.out.println("Job 1 Ongoing");
        Thread emailThread = new Thread(new EmailRunnableThread());
        emailThread.start();
        System.out.println("Job 2 Ongoing");
        FutureTask eFutureTask = new FutureTask<>(new ETACalculator("BLR"));
        Thread etaThread = new Thread(eFutureTask);
        etaThread.start();
        System.out.println("Task 3 Ongoing");

        try {
            emailThread.join(); //Join used to wait till the tasks are completed
            smsThread.join();
            String eta = (String) eFutureTask.get();
            System.out.println(eta);
            etaThread.join();
            System.out.println("Tasks Completed");
            
        } catch (InterruptedException e) {
        }
    }    
}

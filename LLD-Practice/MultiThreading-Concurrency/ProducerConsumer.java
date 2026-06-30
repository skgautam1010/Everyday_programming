
import java.util.LinkedList;
import java.util.Queue;

class ProducerConsumerProblem {

    private boolean isCoffeeReady = false;

    public synchronized void makeCoffeee() throws InterruptedException {

        while(isCoffeeReady) {
            wait();
        }

        System.out.println("Coffee is getting Ready");
        Thread.sleep(1000);
        isCoffeeReady = true;
        System.out.println("Coffee is Ready");
        notify();
        
    }

    public synchronized void drinkCoffee() throws InterruptedException {

        while(!isCoffeeReady) {
            wait();
        }
        
        System.out.println("Coffee is being Consumed");
        Thread.sleep(2000);
        isCoffeeReady = false;
        System.out.println("Coffee Consumed......Ready for next..");
        notify();
    }
}

class Submission {
    private static int idCounter = 1; // Used to generate unique submission IDs
    private final int submissionId;
    private final String userName;

    public Submission(String userName) {
        this.userName = userName;
        this.submissionId = idCounter++; // Auto-incrementing ID
    }

    public int getSubmissionId() {
        return submissionId;
    }

    public String getUserName() {
        return userName;
    }
}

class SubmissionQueue {

    private Queue<Submission> buffer = new LinkedList<>();
    private final int MAX_CAPACITY = 5;

    public synchronized void produce(Submission submission) throws InterruptedException {
        while(buffer.size() == MAX_CAPACITY) {
            System.out.println("⏳ Queue full. " + submission.getUserName() + " is waiting to submit.");
            wait();
        }
        Thread.sleep(100);
        buffer.add(submission);
        System.out.println("" + submission.getUserName() + " submitted code: #" + submission.getSubmissionId());
        notifyAll();
    }

    public synchronized Submission consume() throws InterruptedException {

        while(buffer.isEmpty()) {
            System.out.println("△ waiting for submissions...");
            wait();
        }
        Thread.sleep(100);
        Submission sub = buffer.poll();
        System.out.println("⚙️ started evaluating submission #" +
                           sub.getSubmissionId() + " from " + sub.getUserName());
        notifyAll();
        return sub;
    }
}


public class ProducerConsumer {
    public static void main(String[] args) {
        //ProducerConsumerProblem producerConsumerProblem = new ProducerConsumerProblem();
        SubmissionQueue queue = new SubmissionQueue();

        Thread producer = new Thread(() -> {
            while (true) { 
                try {
                    //producerConsumerProblem.makeCoffeee();
                    for(int i = 1 ;i<=6;i++) {
                        queue.produce(new Submission("user " + i));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            
        });

        Thread consumer = new Thread(() -> {

            while (true) { 
                try {
                    //producerConsumerProblem.drinkCoffee();
                    Submission subVal = queue.consume();
                    System.out.println("Evaluation Completed for user : " + subVal.getUserName());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        producer.start();
        consumer.start();

    }
}

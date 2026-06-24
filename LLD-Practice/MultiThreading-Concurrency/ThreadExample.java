
class SmsThread extends Thread {

    public void run() {
        try {
            Thread.sleep(2000);
            System.out.println("SMS Sent Successfully");
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class EmailThread extends Thread {

    public void run() {
        try {
            Thread.sleep(3000);
            System.out.println("Email Sent Successfully");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    }
}


public class ThreadExample {
    public static void main(String[] args) {
        SmsThread sms = new SmsThread();
        EmailThread email = new EmailThread();
        sms.start(); //Start helps in executing the task in a seperate thread. Start internally calls run.
        System.out.println("Task 1 Ongoing");
        email.start();
        System.out.println("Task 2 Ongoing");

        try {
            email.join(); //Join used to wait till the tasks are completed
            sms.join();
            System.out.println("Tasks Completed");
        } catch (InterruptedException e) {
        }
    }    
}

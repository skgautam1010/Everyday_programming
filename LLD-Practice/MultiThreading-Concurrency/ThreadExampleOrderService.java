public class ThreadExampleOrderService {
    public static void main(String[] args) {
        System.out.println("Order Received");
        System.out.println("Task 1 done");
        Thread smsThread = new Thread(() -> sendSms());
        smsThread.start();
        //sendSms();
        System.out.println("Task 2 Done");
        Thread emailTread = new Thread(() -> sendEmail());
        emailTread.start();
        //sendEmail();
        System.out.println("Task 3 Done");
        String eta = estimateEta();
        System.out.println("Estimated Time: " + eta);
        System.out.println("Task 4 Done");        
    }

    public static void sendSms() {
        try {
            Thread.sleep(2000); //Simulate Delay
            System.out.println("Sms Sent");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } 
    }

    public static void sendEmail() {
        try{
            Thread.sleep(3000);
            System.out.println("Email Sent");
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static String estimateEta() {
        try{
            Thread.sleep(5000);
            System.out.println("Estimates Completed");
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
        return "20 Minutes";
    }
}
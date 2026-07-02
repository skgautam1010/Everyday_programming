

class BankAccount {
    private final String name;
    private double balance;

    public BankAccount(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    public String getName() {
        return name;
    }

    public double getBalanace() {
        return balance;
    }

    public synchronized void addBalance(double amount) {
        balance += amount;
    }

    public synchronized void decuctBalance(double amount) {
        balance -= amount;
    }

}


class Transfer implements Runnable{

    private final BankAccount from;
    private final BankAccount to;
    private double amount;

    public Transfer(BankAccount from, BankAccount to, double amount) {
        this.from = from;
        this.to = to;
        this.amount = amount;
    }


    @Override
    public void run() {
        
        synchronized (from) {
                System.out.println(Thread.currentThread().getName() + " locked " + from.getName());

                try {
                    Thread.sleep(100);
                } catch (Exception e) {
                } 
            synchronized (to) {
                System.out.println(Thread.currentThread().getName() +
                                   " locked " + to.getName());
                from.decuctBalance(amount);
                to.addBalance(amount);
                System.out.println("Transferred " + amount + " from " +
                                   from.getName() + " to " + to.getName());
            }
        }
    }

}




public class Deadlock {
    public static void main(String[] args) throws InterruptedException {
        
        BankAccount accA = new BankAccount("Account A", 1000);
        BankAccount accB = new BankAccount("Account B", 1500);

        Thread t1 = new Thread(new Transfer(accA, accB, 100));
        Thread t2 = new Thread(new Transfer(accB, accA, 300));

        t1.start();
        t2.start();

        t1.join();
        t2.join();
        System.out.println("Completed");
    }
}

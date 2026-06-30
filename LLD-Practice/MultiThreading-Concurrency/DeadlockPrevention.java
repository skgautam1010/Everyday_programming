
import java.util.Arrays;

public class DeadlockPrevention {


    static class Resource {
        int id;
        int value;

        public Resource(int id, int value) {
            this.id = id;
            this.value = value;
        }


        
    }

    public static void transfer(Resource r1, Resource r2, int amount) {
        Resource[] locks = new Resource[]{r1,r2};
        Arrays.sort(locks, (x,y) -> Integer.compare(x.id, y.id));
        synchronized (locks[0]) {
            System.out.println(Thread.currentThread().getName() +
                               " locked " + locks[0].id);

            try {
                Thread.sleep(1000);
            } catch (Exception e) {
            }

            synchronized (locks[1]) {
                 System.out.println(Thread.currentThread().getName() +
                                   " locked " + locks[1].id);
                System.out.println("Transferred " + amount +
                                   " from " + r1.id + " to " + r2.id);
            }
        }
    }

    public static void main(String[] args) {
        Resource r1 = new Resource(101, 5000);
        Resource r2 = new Resource(102, 1000);

        Runnable task1 = () -> transfer(r1, r2, 50);
        Runnable task2 = () -> transfer(r2, r1, 100);

        new Thread(task1, "T1").start();
        new Thread(task2, "T2").start();
    }
}

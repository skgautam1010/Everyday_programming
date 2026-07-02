
import java.util.concurrent.atomic.AtomicInteger;


class CounterIncrement {
    private static int count=0;

    public void incrementCount() {
        synchronized(this) {
            count++;
        }
    }

    public int getCount() {
        return count;
    }
}

class SynchronizedCounterIncrement {
    //private static int count=0;
    private volatile int count=0;

    public synchronized void incrementCount() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

class InstaAtomicCounter {
    private AtomicInteger likes = new AtomicInteger(0);

    public void incrementCount() {
        int prev, next;
        do { 
            prev = likes.get();
            next = prev + 1;
        } while (!likes.compareAndSet(prev, next));
    }

    public int getCount() {
        return likes.get();
    }
}



public class RaceConditionThreadSafety {
    public static void main(String[] args) throws InterruptedException {
        CounterIncrement increment = new CounterIncrement();
        SynchronizedCounterIncrement syncIncrement = new SynchronizedCounterIncrement();
        InstaAtomicCounter  atomicCounter = new InstaAtomicCounter();

        Runnable task = () -> {
            for(int i=0;i<1000;i++) {
                //increment.incrementCount();
                atomicCounter.incrementCount();
            }
        };

        Thread t1 = new Thread(task);
        Thread t2 = new Thread(task);

        t1.start();
        t2.start();
        t1.join();
        t2.join();

        System.out.println("Get the count: " + atomicCounter.getCount());
    }
}

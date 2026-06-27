
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;


class MovieBooking {
    private int availableSeat = 1;
    private ReentrantLock reentrantLock = new ReentrantLock();

    public void bookTicket(String User) {
        System.out.println(User + " is trying to do the booking");
        reentrantLock.lock();

        try {
            System.out.println("Acquring the lock");
            if(availableSeat > 0) {
                System.out.println(User + " successfully booked the ticket");
                availableSeat--;
            } else {
                System.out.println("could not book the seat");
            }
        } catch (Exception e) {
        } finally {
            System.out.println(User + " is releasing the lock");
            reentrantLock.unlock();

        }
    }
}

class ExpiringReentrantLocak {
    private ReentrantLock reentrantLock = new ReentrantLock();

    private ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
    private volatile boolean isLocked = false;

    public boolean tryLockWithExpiry(long timoutMilliSecond) {
        boolean acquired = reentrantLock.tryLock();
        if(acquired) {
            isLocked = true;

            executorService.schedule(() -> {
                if(reentrantLock.isHeldByCurrentThread() || isLocked) {
                    System.out.println("Auto Releasing the lock");
                    unlockSafely();
                }
            }, timoutMilliSecond, TimeUnit.MILLISECONDS);
        }
        return acquired;
    }

    public void unlockSafely() {
        if(reentrantLock.isHeldByCurrentThread() || isLocked) {
            isLocked = false;
            if(reentrantLock.isHeldByCurrentThread()) {
                reentrantLock.unlock();
                System.out.println("Lock Released");
            }
        }
    }
}

class MovieBookingRetryLock {
    private int availableSeat = 1;
    private  final ReentrantLock lock = new ReentrantLock();

    public void bookTicket() {
        boolean acquired = false;
        try {
            acquired = lock.tryLock(2, TimeUnit.SECONDS);
            if(acquired) {
                if(availableSeat > 0) {
                    availableSeat--;
                } else {
                    System.out.println("Could not book the seat");
                }
            } else {
                System.out.println("Could not acquire the lock");
            }
        } catch (Exception e) {
        } finally {
            if(acquired) {
                lock.unlock();
            }
        }
        

    }
}

class StockMarket {
    private double price = 100.0;
    private ReentrantReadWriteLock lock = new ReentrantReadWriteLock();

    public void writeLock(double newPrice) {
        lock.writeLock().lock();
        try {
            System.out.println(Thread.currentThread().getName() + " updating price to : " + newPrice);
            price = newPrice;
        } finally {
            lock.writeLock().unlock();
        }
    }

    public void readLock() {
        lock.readLock().lock();
        try {
            System.out.println(Thread.currentThread().getName() + " read price: " + price);
        } finally {
            lock.readLock().unlock();
        }
    }
}



public class ReentrantLockMutex {
    public static void main(String[] args) {
        
    }
}

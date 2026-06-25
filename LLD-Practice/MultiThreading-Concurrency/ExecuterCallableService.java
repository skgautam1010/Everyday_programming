
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class ExecuterCallableService {
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        Future<Integer> future = executorService.submit(() -> {
            Thread.sleep(1000);
            return 40;
        });
        
        System.out.println("Doing other work");

        Integer result = future.get();
        System.out.println("Result: " + result);
        executorService.shutdown();
        
    }
}
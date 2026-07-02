//Classic Example when not injecting DI

/*class OrderService {
    private InventoryService inventory = new InventoryService();
    private PaymentService payment = new RazorpayPayment();
    private NotificationService notification = new NotificationService();

    public void checkout(Order order) {
        inventory.blockItems(order);
        payment.process(order);
        notification.sendConfirmation(order);
    }
}*/


/*class OrderService {
    private InventoryService inventoryService;
    private PaymentService paymentService;
    private NotificationService notificationService;

    public OrderService(InventoryService inventoryService, 
                         PaymentService paymentService,
                         NotificationService notificationService) {
            this.inventoryService = inventoryService;
            this.paymentService = paymentService;
            this.notificationService = notificationService;
                         }
    public void checkout(Order order) {
        inventoryService.blockItems(order);
        paymentService.process(order);
        notificationService.sendConfirmation(order);
    }
}

// Using Setter Injection
public class OrderService2 {
    private PaymentService payment;

    // Setter method to inject dependencies
    public void setPayment(PaymentService payment) {
        this.payment = payment;
    }

    public void checkout(Order order) {
        payment.process(order);
    }
}


// Interface to inject PaymentService dependency
public interface PaymentInjectable {
    // Method to inject PaymentService
    void injectPayment(PaymentService payment);
}

// Using Interface Injection
public class OrderService implements PaymentInjectable {
    private PaymentService payment;

    // Inject PaymentService through the method
    @Override
    public void injectPayment(PaymentService payment) {
        this.payment = payment; // Set the injected payment service
    }

    
    public void checkout(Order order) {
        payment.process(order); 
    }
}
*/

interface NotificationService {
    void send(String message);
}

class EmailNotificationService implements NotificationService {
    @Override
    public void send(String message) {
        System.out.println("Email sent: " + message);
    }
}

class UserService {
    // Dependency held as an interface, promoting loose coupling
    private final NotificationService notificationService;

    // Constructor Injection: forces the caller to supply the dependency up-front
    public UserService(NotificationService notificationService) {
        this.notificationService = notificationService;
    }

    // Business logic uses the injected service
    public void register(String user) {
        System.out.println("User registered: " + user);
        notificationService.send("Welcome " + user);
    }
}


public class DependencyInject {
    public static void main(String[] args) {
        //OrderService orderService = new OrderService(new InventoryService(), new PaymentService(), new NotificationService());
        //orderService.checkout(order);

         NotificationService service = new EmailNotificationService();

        // Inject it into the client
        UserService userService = new UserService(service);

        // Execute business operation
        userService.register("sonu");
    }
}

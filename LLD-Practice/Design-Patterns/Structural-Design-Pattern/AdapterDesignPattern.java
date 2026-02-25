
interface PaymentGateway {
    void pay(String orderId, String amount);
}


class PayuGateway implements PaymentGateway {
    @Override
    public void pay(String orderId, String amount) {
        System.out.println("Payment made with " + orderId + " of amount : " + amount);
    }
}

class RazorPayApi {
    public void makePayment(String invoiceId, String amount) {
        System.out.println("Payment made with razorPay " + invoiceId + " of amount : " + amount);
    }
}


class RazorPayAdapter implements PaymentGateway {
    private RazorPayApi razorPayApi;
    public RazorPayAdapter() {
        this.razorPayApi = new RazorPayApi();
    }

    @Override
    public void pay(String orderId, String amount) {
        razorPayApi.makePayment(orderId, amount);
    }
}


class CheckOutService {
    private PaymentGateway paymentGateway;

    public CheckOutService(PaymentGateway paymentGateway) {
        this.paymentGateway = paymentGateway;
    }

    public void checkout(String orderId, String amount) {
        paymentGateway.pay(orderId, amount);
    }
}

public class AdapterDesignPattern {
    public static void main(String[] args) {
        CheckOutService checkOutService = new CheckOutService(new PayuGateway());
        checkOutService.checkout("123", "1200");
        CheckOutService checkOutService1 = new CheckOutService(new RazorPayAdapter());
        checkOutService1.checkout("456", "2000");
    }    
}

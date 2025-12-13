interface cancellable {
    void cancelRide();
}
interface RiderInterace extends cancellable {
    void bookRide();
    void payRide();
}
interface DriverInterface extends cancellable {
    void acceptRide();
    void endRide();
    void drive();
}

class Rider implements RiderInterace {
    public void bookRide() {
        System.out.println("Book");
    }
    public void payRide() {
        System.out.println("Pay rider");
    }
    public void cancelRide() {
        System.out.println("cancelled by rider");
    }
}
class Driver implements DriverInterface {
    public void acceptRide() {
        System.out.println("accept ride");
    }
    public void endRide() {
        System.out.println("end ride");
    }
    public void drive() {
        System.out.println("drive to dest.");
    }
    public void cancelRide() {
        System.out.println("ride cancel by driver");
    }
}

public class InterfaceSegregation {

    public static void main(String[] args) {
        Driver driver = new Driver();
        driver.cancelRide();
        driver.acceptRide();
    }
}
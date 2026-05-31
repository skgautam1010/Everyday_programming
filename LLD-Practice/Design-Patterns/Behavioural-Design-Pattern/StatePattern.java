
/*class Order {
    private String state;

    public Order() {
        this.state = "ORDER_PLACED";
    }

    public void cancelOrder() {
        if(state.equals("ORDER_PLACED") || state.equals("PREPARING")) {
            state = "CANCELLED";
            System.out.println("Order Canceled");
        } else {
            System.out.println("Order Cannot be cancelled");
        }
    }

    public void nextState() {
        switch(state) {
            case "ORDER_PLACED" :
                state = "PREPARING";
                break;
            case "PREPARING":
                state = "OUT_FOR_DELIVERY";
                break;
            case "OUT_FOR_DELIVERY":
                state = "DELIVERED";
                break;
            default:
                System.out.println("Not next state from: " + state);
        }
    }

    public String getState() {
        return state;
    }
}*/

class OrderContext {

    private OrderState currentState;

    public OrderContext() {
        this.currentState = new OrderPlacedState();
    }

    public void setState(OrderState orderState) {
        this.currentState = orderState;
    }

    public void next() {
        currentState.nextState(this);
    }

    public void cancel() {
        currentState.cancelOrder(this);
    }

    public String getCurrentStateName() {
        return currentState.getStateName();
    }

}

interface OrderState {
    void nextState(OrderContext orderContext);
    void cancelOrder(OrderContext orderContext);
    String getStateName();
}


class OrderPlacedState implements OrderState {

    @Override
    public void nextState(OrderContext orderContext) {
        orderContext.setState(new OrderPreparingState());
        System.out.println("Order is now being prepared");
    }

    @Override
    public void cancelOrder(OrderContext orderContext) {
        orderContext.setState(new CancelledOrder());
        System.out.println("Order has been cancelled.");
    }

    @Override
    public String getStateName() {
        return "ORDER_PLACED";
    }
    
}

class OrderPreparingState implements OrderState {

    @Override
    public void nextState(OrderContext orderContext) {
        orderContext.setState(new OutForDeliveryState());
        System.out.println("Order is out for delivery.");
    }

    @Override
    public void cancelOrder(OrderContext orderContext) {
        orderContext.setState(new CancelledOrder());
        System.out.println("Order has been cancelled.");
    }

    @Override
    public String getStateName() {
        return "PREPARING";
    }
    
}

class OutForDeliveryState implements OrderState {

    @Override
    public void nextState(OrderContext orderContext) {
        orderContext.setState(new DeliveredState());
        System.out.println("Order has been delivered.");
    }

    @Override
    public void cancelOrder(OrderContext orderContext) {
        System.out.println("Cannot cancel. Order is out for delivery.");
    }

    @Override
    public String getStateName() {
        return "OUT_FOR_DELIVERY";
    }
}

class DeliveredState implements OrderState {

    @Override
    public void nextState(OrderContext orderContext) {
        System.out.println("Order is already delivered.");
    }

    @Override
    public void cancelOrder(OrderContext orderContext) {
         System.out.println("Cannot cancel a delivered order.");
    }

    @Override
    public String getStateName() {
        return "DELIVERED";
    }
    
}

class CancelledOrder implements OrderState {

    @Override
    public void nextState(OrderContext orderContext) {
       System.out.println("Cancelled order cannot move to next state.");
    }

    @Override
    public void cancelOrder(OrderContext orderContext) {
        System.out.println("Order is already cancelled.");
    }

    @Override
    public String getStateName() {
        return "CANCELLED";
    }
    
}


public class StatePattern {
    public static void main(String[] args) {
        OrderContext orderContext = new OrderContext();
        System.out.println(orderContext.getCurrentStateName());
        orderContext.next();
        orderContext.next();
        orderContext.cancel();
        orderContext.next();
        orderContext.next();
        orderContext.cancel();
        System.out.println("Current Order State: " + orderContext.getCurrentStateName());
    }
}
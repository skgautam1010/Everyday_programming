
abstract class SupportHandler {
    protected SupportHandler supportHandler;
    

    public void setNextHandler(SupportHandler supportHandler) {
        this.supportHandler = supportHandler;
    }

    protected abstract void handleRequest(String requestType);

}


class GeneralSupport extends SupportHandler {

    @Override
    protected void handleRequest(String requestType) {
        if(requestType.equalsIgnoreCase("General")) {
            System.out.println("Generic Support : Handling this request");
        } else {
            if(supportHandler != null) {
                supportHandler.handleRequest(requestType);
            }
        }
    }
}

class BillingSupport extends SupportHandler {

    @Override
    protected void handleRequest(String requestType) {
        if(requestType.equalsIgnoreCase("Billing") || requestType.equalsIgnoreCase("finance")) {
            System.out.println("Billing Support : Handling this request");
        } else {
            if(supportHandler !=null) {
                supportHandler.handleRequest(requestType);
            }
        }
    }
}

class TechnicalSupport extends SupportHandler {

    @Override
    protected void handleRequest(String requestType) {
        if(requestType.equalsIgnoreCase("Technical")) {
            System.out.println("Technical Support : Handling this request");
        } else {
            if(supportHandler != null) {
                supportHandler.handleRequest(requestType);
            }
        }
    }
    
}

class DeliverySupport extends SupportHandler {

    @Override
    protected void handleRequest(String requestType) {
        if(requestType.equalsIgnoreCase("Delivery")) {
            System.out.println("Delivery Support: Handling this request");
        } else {
            if(supportHandler != null) {
                supportHandler.handleRequest(requestType);
            } else {
                System.out.println("No Handler Present to handle the request");
            }
        }
    }
    
}


public class ChainOfResponsiblity {
    public static void main(String[] args) {
        SupportHandler generic = new GeneralSupport();
        SupportHandler billing = new BillingSupport();
        SupportHandler technical = new TechnicalSupport();
        SupportHandler delivery = new DeliverySupport();
        generic.setNextHandler(billing);
        billing.setNextHandler(technical);
        technical.setNextHandler(delivery);
        generic.handleRequest("billing");
        technical.handleRequest("delivery");
        generic.handleRequest("finance");
    }
}

interface Logistics {
    void send();
}


class Road implements Logistics {

    @Override
    public void send() {
        System.out.println("Sent via Road");
    }
}

class Air implements Logistics {

    @Override
    public void send() {
        System.out.println("Sent via Air");
    }
}


class LogisticsFactory {
    public static Logistics getLogistics(String mode) {
        if(mode =="air") {
            return new Air();
        }
        return new Road();
    }
}




public class FactoryDesignPattern {
    public void send(String mode) {
        Logistics logistics = LogisticsFactory.getLogistics(mode);
        logistics.send();
    }
    public static void main(String[] args) {
        FactoryDesignPattern factoryDesignPattern = new FactoryDesignPattern();
        factoryDesignPattern.send("air");
    }
}

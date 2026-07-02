interface MatchingStrategy {
    void match(String riderLocation);
}

/*class RideMatchingService {
    public void matchRider(String riderLocation, String matchingType) {
        // Match rider using different hardcoded strategies
        if (matchingType.equals("NEAREST")) {
            // Find nearest driver
            System.out.println("Matching rider at " + riderLocation + " with nearest driver.");
        } else if (matchingType.equals("SURGE_PRIORITY")) {
            // Match based on surge area logic
            System.out.println("Matching rider at " + riderLocation + " based on surge pricing priority.");
        } else if (matchingType.equals("AIRPORT_QUEUE")) {
            // Use FIFO-based airport queue logic
            System.out.println("Matching rider at " + riderLocation + " from airport queue.");
        } else {
            System.out.println("Invalid matching strategy provided.");
        }
    }
}*/



class NearestDriverStrategy implements MatchingStrategy {

    @Override
    public void match(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " with nearest driver.");
    }
}

class AirportQueueStrategy implements MatchingStrategy {

    @Override
    public void match(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " from airport queue.");
    }
}

class PriceSurgeStrategy implements MatchingStrategy {

    @Override
    public void match(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " based on surge pricing priority.");
    }
}

class RideMatchingService {
    private MatchingStrategy matchingStrategy;

    public RideMatchingService(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }
    public void setStartegy(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }
    public void matchRider(String riderLocation) {
        matchingStrategy.match(riderLocation);
    }
}

public class StrategyPattern {
    public static void main(String[] args) {
        RideMatchingService rideMatchingService = new RideMatchingService(new NearestDriverStrategy());
        rideMatchingService.matchRider("abbdddd");
        RideMatchingService rideMatchingService1 = new RideMatchingService(new AirportQueueStrategy());
        rideMatchingService1.matchRider("airportaass");
        rideMatchingService1.setStartegy(new PriceSurgeStrategy());
        rideMatchingService1.matchRider("surgeefdfd");
    }
}


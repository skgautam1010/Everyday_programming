
import java.util.Arrays;
import java.util.List;

class BurgerMeal {
    
    //Required
    private final String bunType;
    private final String patty;

    //Optional

    private final boolean hasCheese;
    private final List<String> toppings;
    private final String side;
    private final String drink;

    // Private constructor to force use of Builder
    private BurgerMeal(BurgerBuilder burgerBuilder) {
            this.bunType = burgerBuilder.bunType;
            this.patty = burgerBuilder.patty;
            this.hasCheese = burgerBuilder.hasCheese;
            this.toppings = burgerBuilder.toppings;
            this.side = burgerBuilder.side;
            this.drink = burgerBuilder.drink;
    }

    public static class BurgerBuilder {

        private final String bunType;
        private final String patty;

        //Optional

        private boolean hasCheese;
        private List<String> toppings;
        private String side;
        private String drink;

        public BurgerBuilder(String bunType, String patty) {
            this.bunType = bunType;
            this.patty = patty;
        }

        public BurgerBuilder withCheese(boolean hasCheese) {
            this.hasCheese = hasCheese;
            return this;
        }
        public BurgerBuilder withToppings(List<String> toppings) {
            this.toppings = toppings;
            return this;
        }
        // Method to set side
        public BurgerBuilder withSide(String side) {
            this.side = side;
            return this;
        }

        // Method to set drink
        public BurgerBuilder withDrink(String drink) {
            this.drink = drink;
            return this;
        }

        public BurgerMeal build() {
            return new BurgerMeal(this);
        }
        
    }
}

/*@Builder Lombok provides annotation @ Builder
Lombok is a Java library that reduces boilerplate code using annotations. One of its popular features is the @Builder annotation, which automatically generates a builder class behind the scenes.
public class User {
    private String name;
    private int age;
    private String address;
}
*/

public class BuilderDesignPattern {
    public static void main(String[] args) {
        BurgerMeal burgerMeal = new BurgerMeal.BurgerBuilder("wheat","veg").build();
        System.out.println(burgerMeal);
        BurgerMeal burgerWithCheese = new BurgerMeal.BurgerBuilder("wheat", "veg")
                                        .withCheese(true)
                                        .build();
        List<String> toppings = Arrays.asList("lettuce", "onion", "jalapeno");
        BurgerMeal loadedBurger = new BurgerMeal.BurgerBuilder("multigrain", "chicken")
                                        .withCheese(true)
                                        .withToppings(toppings)
                                        .withSide("fries")
                                        .withDrink("coke")
                                        .build();
        System.out.println(loadedBurger);
        /*User user = User.builder()
            .name("John")
            .age(30)
            .address("NYC")
            .build();*/
    }
    
}


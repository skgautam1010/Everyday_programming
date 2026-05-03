
interface Pizza {
    String getDescription();
    int getCost();
}

//Concrete Class
class MargretiaPizza implements Pizza {

    @Override
    public String getDescription() {
        return "Margerita Pizza";
    }

    @Override
    public int getCost() {
        return 200;
    } 
}

// ======================== Abstract Decorator ===========================
// ====== Implements Pizza and holds a reference to a Pizza object =======

abstract class PizzaDecorator implements Pizza {
    protected Pizza pizza;
    
    public PizzaDecorator(Pizza pizza) {
        this.pizza = pizza;
    }
}

class CheesePizza extends PizzaDecorator {

    public CheesePizza(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.getDescription() + " Cheese Toppings added";
    }

    @Override
    public int getCost() {
        return pizza.getCost() + 40;
    }
    
}

class OlivePizza extends PizzaDecorator {

    public OlivePizza(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.getDescription() + " Olive Added";
    }

    @Override
    public int getCost() {
        return pizza.getCost() + 10;
    }
    
}


public class DecoratorDesignPattern {
    public static void main(String[] args) {
        Pizza pizza = new MargretiaPizza();
        pizza = new OlivePizza(pizza); 
        pizza = new CheesePizza(pizza);
        System.out.println("Pizza Description: "+ pizza.getDescription());
        System.out.println(pizza.getCost());
    }
}
import java.util.ArrayList;
import java.util.List;

interface CartItem {
    double getCartPrice();
}


class ProductData implements CartItem {

    private String productName;
    private double price;

    public ProductData(String productName, double price) {
        this.productName = productName;
        this.price = price;
    }

    @Override
    public double getCartPrice() {
        return price;
    }
    
}

class ProductBundle implements CartItem {

    private String productBundleName;
    private List<CartItem> items = new ArrayList<>();

    public ProductBundle(String bundleName) {
        this.productBundleName = bundleName;
    }

    public void addItem(CartItem item) {
        items.add(item);
    }

    @Override
    public double getCartPrice() {
        double total = 0;
        for(CartItem item : items) {
            total += item.getCartPrice();
        }
        return total;
    }
}



public class CompositePattern {
    public static void main(String[] args) {
        CartItem books = new ProductData("NCERT Books", 200.00);
        CartItem charger = new ProductData("Iphone Charger", 1000.0);
        CartItem earbirds = new ProductData("Iphone EarBirds", 2000);

        ProductBundle iphProductBundle = new ProductBundle("Iphone Product Bundle");
        iphProductBundle.addItem(charger);
        iphProductBundle.addItem(earbirds);

        ProductBundle schoolKit = new ProductBundle("School Kit");
        schoolKit.addItem(books);
        schoolKit.addItem(new ProductData("Dress", 2500));
        schoolKit.addItem(new ProductData("Notebook", 3000));

        List<CartItem> items = new ArrayList<>();
        items.add(books);
        items.add(charger);
        items.add(iphProductBundle);
        items.add(schoolKit);

    
        double total = 0;
        for(CartItem item : items) {
            total += item.getCartPrice();
        }
        System.out.println("Your total Cart Price is : " + total);
    }
}

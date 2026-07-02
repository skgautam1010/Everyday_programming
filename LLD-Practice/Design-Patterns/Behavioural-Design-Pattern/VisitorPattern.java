import java.util.ArrayList;
import java.util.List;

interface Item {
    void accept(ItemVisitor visitor);
}


//Element

class PhysicalItem implements Item {

    protected String name;
    protected  double weight;

    public PhysicalItem(String name, double weight) {
        this.name = name;
        this.weight = weight;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
    
}

class DigitalItem implements Item {

    protected String name;
    protected int downlodableSizeInMb;

    public DigitalItem(String name, int downloadableSizeInMb) {
        this.name = name;
        this.downlodableSizeInMb = downloadableSizeInMb;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
    
}

class GiftCard implements Item {

    protected  String couponCode;
    protected double discount;

    public GiftCard(String couponCode, double discount) {
        this.couponCode = couponCode;
        this.discount = discount;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
    
}


//Visitor

interface ItemVisitor {
    void visit(PhysicalItem item);
    void visit(DigitalItem item);
    void visit(GiftCard item);
}


class InvoiceGenerationVisitor implements ItemVisitor {

    @Override
    public void visit(PhysicalItem item) {
        System.out.println("Invoice: " + item.name + " - Shipping to customer");
    }

    @Override
    public void visit(DigitalItem item) {
        System.out.println("Invoice: " + item.name + " - Email with download link");
    }

    @Override
    public void visit(GiftCard item) {
        System.out.println("Invoice: Gift Card - Code: " + item.couponCode);
    }

}

class ShippingCostVisitor implements ItemVisitor {

    @Override
    public void visit(PhysicalItem item) {
        System.out.println("Shipping cost for " + item.name + ": Rs. " + (item.weight * 10));
    }

    @Override
    public void visit(DigitalItem item) {
       System.out.println(item.name + " is digital -- No shipping cost.");
    }

    @Override
    public void visit(GiftCard item) {
       System.out.println("GiftCard delivery via email -- No shipping cost.");
    }
    
}


public class VisitorPattern {
    public static void main(String[] args) {
        List<Item> items = new ArrayList<>();
        items.add(new PhysicalItem("Book", 2));
        items.add(new DigitalItem("E-Book", 50));
        items.add(new GiftCard("XYZTUF+", 500));

        InvoiceGenerationVisitor invoiceGenerationVisitor = new InvoiceGenerationVisitor();
        ShippingCostVisitor shippingCostVisitor = new ShippingCostVisitor();

        for(Item item : items) {
            item.accept(invoiceGenerationVisitor);
            item.accept(shippingCostVisitor);
        }
    }
}

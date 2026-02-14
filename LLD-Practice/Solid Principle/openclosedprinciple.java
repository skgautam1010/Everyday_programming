interface TaxCalculator {
    double amountAfterTax(double amount);
}

class IndianTaxCalculator implements TaxCalculator{
    public double amountAfterTax(double amount) {
        return (amount + 0.15 * amount);
        
    }
}
class USTaxCalculator implements TaxCalculator {
    public double amountAfterTax(double amount) {
        return amount + 0.10 * amount;
    }
}
class InvoiceService {
    public void calculate() {
        TaxCalculator taxCalculator = new IndianTaxCalculator();
        double amount = 1000.0;
        double totalAmount = taxCalculator.amountAfterTax(amount);
        System.out.println("Total Amount after tax: " + totalAmount);
    }
}
class Main {
    public static void main(String[] args) {
        InvoiceService invoiceService = new InvoiceService();
        invoiceService.calculate();
    }
}
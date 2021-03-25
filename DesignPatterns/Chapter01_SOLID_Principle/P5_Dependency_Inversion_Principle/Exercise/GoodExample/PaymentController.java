package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.GoodExample;

// pure abstract layer
public class PaymentController {
    
    private PaymentMethod paymentMethod;

    public PaymentController() {

    }

    // we can change the behavior at runtime
    public void setPaymentMethod(PaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    public void pay() {
        this.paymentMethod.pay();
    }
    
}

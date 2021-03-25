package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.BadExample;

public class PaymentController {
    
    // private Payoneer paymentMethod;
    // private PayPal paymentMethod;
    private Skrill paymentMethod;

    public PaymentController() {

    }

    // public void setPaymentMethod(Payoneer payoneer) {
    //     this.paymentMethod = payoneer;
    // }

    // public void setPaymentMethod(PayPal payPal) {
    //     this.paymentMethod = payPal;
    // }

    public void setPaymentMethod(Skrill skrill) {
        this.paymentMethod = skrill;
    }

    public void pay() {
        this.paymentMethod.pay();
    }

}

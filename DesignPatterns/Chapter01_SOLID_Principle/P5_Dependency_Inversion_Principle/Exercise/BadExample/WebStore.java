package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.BadExample;

public class WebStore {
    
    private PaymentController controller;

    public WebStore() {
        controller = new PaymentController();
        // controller.setPaymentMethod(new PayPal());
        // controller.setPaymentMethod(new Payoneer());
        controller.setPaymentMethod(new Skrill());
    }

    public void purchaseItem() {
        this.controller.pay();
    }
}

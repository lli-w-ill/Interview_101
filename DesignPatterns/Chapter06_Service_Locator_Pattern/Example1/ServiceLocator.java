package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

public class ServiceLocator {

    private static Cache cache = new Cache();

    // jndiName: Java Naming and Directory Interface Name
    public static Service getService(String jndiName) {

        Service service = cache.getService(jndiName);

        if (service != null) {
            return service;
        }

        // create a new service
        InitialContext context = new InitialContext();
        Service s = (Service) context.lookup(jndiName);
        // cache the service
        cache.addService(s);

        return s;
    }

}

package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

import java.util.ArrayList;
import java.util.List;

// stores all services
public class Cache {
    
    private List<Service> listOfServices;

    public Cache() {
        this.listOfServices = new ArrayList<>();
    }

    // return services according to jndiName
    public Service getService(String jndiName) {
        for (Service s : listOfServices) {
            if (s.getName().equals(jndiName)) {
                // have found the service
                return s;
            }
        }

        return null;
    }

    public void addService(Service service) {
        this.listOfServices.add(service);
    }

}

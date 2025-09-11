import java.util.ArrayList;
import java.util.List;

class Patient {
    String name;
    int age;

    public Patient(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Patient[Name=" + name + ", Age=" + age + "]";
    }
}

class Doctor {
    String name;
    String specialty;
    List<Patient> patients;

    public Doctor(String name, String specialty) {
        this.name = name;
        this.specialty = specialty;
        this.patients = new ArrayList<>();
    }

    public void addPatient(Patient patient) {
        this.patients.add(patient);
    }

    public void displayInfo() {
        System.out.println("Doctor: " + this.name + " (" + this.specialty + ")");
        System.out.println("Assigned Patients:");
        if (patients.isEmpty()) {
            System.out.println("  None");
        } else {
            for (Patient p : patients) {
                System.out.println("  - " + p.toString());
            }
        }
    }
}

public class aggration {
    public static void main(String[] args) {
        Patient p1 = new Patient("Sazzad Hossain", 40);
        Patient p2 = new Patient("Toufique", 14);

        Doctor drHouse = new Doctor("Fariha Mithila", "Diagnostician");

        drHouse.addPatient(p1);
        drHouse.addPatient(p2);

        System.out.println("--- Initial State ---");
        drHouse.displayInfo();
        System.out.println();

        System.out.println("--- Destroying Doctor object ---");
        drHouse = null;

        System.out.println("Doctor object is null.");
        System.out.println("Patient objects still exist independently:");
        System.out.println(p1.toString());
        System.out.println(p2.toString());
    }
}

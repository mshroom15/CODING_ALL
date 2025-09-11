#include <iostream>
#include <string>
#include <vector>

class Patient {
private:
    std::string name;
    int age;
    std::string disease;

public:
    Patient(const std::string& patientName, int patientAge, const std::string& patientDisease)
        : name(patientName), age(patientAge), disease(patientDisease) {}

    void displayPatientInfo() const {
        std::cout << "Patient: " << name << ", Age: " << age << ", Disease: " << disease << std::endl;
    }

    std::string getName() const { return name; }
};

class Doctor {
private:
    std::string name;
    std::string specialization;
    std::vector<Patient> patients; // Composition: Doctor owns Patient objects

public:
    Doctor(const std::string& doctorName, const std::string& doctorSpecialization)
        : name(doctorName), specialization(doctorSpecialization) {}

    void addPatient(const std::string& patientName, int age, const std::string& disease) {
        patients.emplace_back(patientName, age, disease);
    }

    void displayDoctorInfo() const {
        std::cout << "Doctor: " << name << ", Specialization: " << specialization << std::endl;
        std::cout << "Patients under care:" << std::endl;
        for (const auto& patient : patients) {
            patient.displayPatientInfo();
        }
    }

    ~Doctor() {
        std::cout << "Doctor " << name << " is destroyed. All patients are also destroyed." << std::endl;
    }
};

int main() {
    Doctor doctor("Dr. Shahana", "Cardiology");
    
    doctor.addPatient("Mozammel", 45, "Heart Disease");
    doctor.addPatient("Kamrul", 35, "Hypertension");
    
    doctor.displayDoctorInfo();
    
    return 0;
}
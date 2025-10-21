#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

class Member {
private:
    int id;
    double height; // in meters
    double weight; // in kg

public:
    Member(int id, double height, double weight) : id(id), height(height), weight(weight) {}

    int getId() const { return id; }
    double getHeight() const { return height; }
    double getWeight() const { return weight; }

    void setHeight(double h) { height = h; }
    void setWeight(double w) { weight = w; }

    double calculateBMI() const {
        return weight / (height * height);
    }

    std::string getBMIClassification() const {
        double bmi = calculateBMI();
        if (bmi < 18.5) return "Underweight";
        else if (bmi < 25) return "Normal weight";
        else if (bmi < 30) return "Overweight";
        else if (bmi < 35) return "Obesity (Class 1)";
        else if (bmi < 40) return "Obesity (Class 2)";
        else return "Extreme Obesity (Class 3)";
    }

    void display() const {
        std::cout << "ID: " << id << ", Height: " << height << "m, Weight: " 
                 << weight << "kg, BMI: " << std::fixed << std::setprecision(2) 
                 << calculateBMI() << " (" << getBMIClassification() << ")" << std::endl;
    }
};

class GymManagement {
private:
    std::vector<Member> members;

public:
    void addMember(int id, double height, double weight) {
        // Check if member with the ID already exists
        for (const auto& member : members) {
            if (member.getId() == id) {
                std::cout << "Member with ID " << id << " already exists!" << std::endl;
                return;
            }
        }
        members.emplace_back(id, height, weight);
        std::cout << "Member added successfully!" << std::endl;
    }

    bool removeMember(int id) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if (it->getId() == id) {
                members.erase(it);
                std::cout << "Member removed successfully!" << std::endl;
                return true;
            }
        }
        std::cout << "Member with ID " << id << " not found!" << std::endl;
        return false;
    }

    bool updateMember(int id, double height, double weight) {
        for (auto& member : members) {
            if (member.getId() == id) {
                member.setHeight(height);
                member.setWeight(weight);
                std::cout << "Member updated successfully!" << std::endl;
                return true;
            }
        }
        std::cout << "Member with ID " << id << " not found!" << std::endl;
        return false;
    }

    void displayAllMembers() const {
        if (members.empty()) {
            std::cout << "No members in the database!" << std::endl;
            return;
        }

        std::cout << "\n------ All Members ------" << std::endl;
        for (const auto& member : members) {
            member.display();
        }
    }

    void displayMemberBMI(int id) const {
        for (const auto& member : members) {
            if (member.getId() == id) {
                member.display();
                return;
            }
        }
        std::cout << "Member with ID " << id << " not found!" << std::endl;
    }

    double calculateAverageHeight() const {
        if (members.empty()) return 0;

        double totalHeight = 0;
        for (const auto& member : members) {
            totalHeight += member.getHeight();
        }
        return totalHeight / members.size();
    }

    double calculateAverageWeight() const {
        if (members.empty()) return 0;

        double totalWeight = 0;
        for (const auto& member : members) {
            totalWeight += member.getWeight();
        }
        return totalWeight / members.size();
    }

    void calculateMaxHeight() const {
        if (members.empty()) {
            std::cout << "No members in the database!" << std::endl;
            return;
        }

        double maxHeight = 0;
        int maxHeightId = 0;
        for (const auto& member : members) {
            if (member.getHeight() > maxHeight) {
                maxHeight = member.getHeight();
                maxHeightId = member.getId();
            }
        }
        std::cout << "Maximum Height: " << maxHeight << "m (Member ID: " << maxHeightId << ")" << std::endl;
    }

    void calculateMaxWeight() const {
        if (members.empty()) {
            std::cout << "No members in the database!" << std::endl;
            return;
        }

        double maxWeight = 0;
        int maxWeightId = 0;
        for (const auto& member : members) {
            if (member.getWeight() > maxWeight) {
                maxWeight = member.getWeight();
                maxWeightId = member.getId();
            }
        }
        std::cout << "Maximum Weight: " << maxWeight << "kg (Member ID: " << maxWeightId << ")" << std::endl;
    }

    void calculateMinHeight() const {
        if (members.empty()) {
            std::cout << "No members in the database!" << std::endl;
            return;
        }

        double minHeight = std::numeric_limits<double>::max();
        int minHeightId = 0;
        for (const auto& member : members) {
            if (member.getHeight() < minHeight) {
                minHeight = member.getHeight();
                minHeightId = member.getId();
            }
        }
        std::cout << "Minimum Height: " << minHeight << "m (Member ID: " << minHeightId << ")" << std::endl;
    }

    void calculateMinWeight() const {
        if (members.empty()) {
            std::cout << "No members in the database!" << std::endl;
            return;
        }

        double minWeight = std::numeric_limits<double>::max();
        int minWeightId = 0;
        for (const auto& member : members) {
            if (member.getWeight() < minWeight) {
                minWeight = member.getWeight();
                minWeightId = member.getId();
            }
        }
        std::cout << "Minimum Weight: " << minWeight << "kg (Member ID: " << minWeightId << ")" << std::endl;
    }

    void displayStatistics() const {
        std::cout << "\n------ Gym Statistics ------" << std::endl;
        std::cout << "Total members: " << members.size() << std::endl;
        
        if (!members.empty()) {
            std::cout << "Average Height: " << std::fixed << std::setprecision(2) 
                     << calculateAverageHeight() << "m" << std::endl;
            std::cout << "Average Weight: " << std::fixed << std::setprecision(2) 
                     << calculateAverageWeight() << "kg" << std::endl;
            
            calculateMaxHeight();
            calculateMaxWeight();
            calculateMinHeight();
            calculateMinWeight();
        }
    }
};

int main() {
    GymManagement gym;
    int choice;
    
    do {
        std::cout << "\n===== Gym Management System =====\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Remove Member\n";
        std::cout << "3. Update Member\n";
        std::cout << "4. Display All Members\n";
        std::cout << "5. Display Member BMI\n";
        std::cout << "6. Display Statistics\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                double height, weight;
                std::cout << "Enter Member ID: ";
                std::cin >> id;
                std::cout << "Enter Height (in meters): ";
                std::cin >> height;
                std::cout << "Enter Weight (in kg): ";
                std::cin >> weight;
                gym.addMember(id, height, weight);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Member ID to remove: ";
                std::cin >> id;
                gym.removeMember(id);
                break;
            }
            case 3: {
                int id;
                double height, weight;
                std::cout << "Enter Member ID to update: ";
                std::cin >> id;
                std::cout << "Enter new Height (in meters): ";
                std::cin >> height;
                std::cout << "Enter new Weight (in kg): ";
                std::cin >> weight;
                gym.updateMember(id, height, weight);
                break;
            }
            case 4:
                gym.displayAllMembers();
                break;
            case 5: {
                int id;
                std::cout << "Enter Member ID to display BMI: ";
                std::cin >> id;
                gym.displayMemberBMI(id);
                break;
            }
            case 6:
                gym.displayStatistics();
                break;
            case 0:
                std::cout << "Thank you for using Gym Management System. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
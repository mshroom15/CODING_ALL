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
    Member(int member_id, double h, double w) : id(member_id), height(h), weight(w) {}

    int get_id() const { return id; }
    double get_height() const { return height; }
    double get_weight() const { return weight; }

    void set_height(double h) { height = h; }
    void set_weight(double w) { weight = w; }

    double calculate_bmi() const {
        if (height == 0) return 0;
        return weight / (height * height);
    }

    std::string get_bmi_classification() const {
        double bmi = calculate_bmi();
        if (bmi < 18.5) return "Underweight";
        if (bmi < 25) return "Normal weight";
        if (bmi < 30) return "Overweight";
        if (bmi < 35) return "Obesity (Class 1)";
        if (bmi < 40) return "Obesity (Class 2)";
        return "Extreme Obesity (Class 3)";
    }

    void display() const {
        std::cout << "ID: " << id << ", Height: " << height << "m, Weight: " 
                 << weight << "kg, BMI: " << std::fixed << std::setprecision(2) 
                 << calculate_bmi() << " (" << get_bmi_classification() << ")" << std::endl;
    }
};

class GymManagement {
private:
    std::vector<Member> members;

public:
    void add_member(int id, double height, double weight) {
        for (const auto& member : members) {
            if (member.get_id() == id) {
                std::cout << "Error: Member with ID " << id << " already exists.\n";
                return;
            }
        }
        members.emplace_back(id, height, weight);
        std::cout << "New member added.\n";
    }

    void remove_member(int id) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if (it->get_id() == id) {
                members.erase(it);
                std::cout << "Member removed.\n";
                return;
            }
        }
        std::cout << "Could not find member with ID " << id << ".\n";
    }

    void update_member(int id, double height, double weight) {
        for (auto& member : members) {
            if (member.get_id() == id) {
                member.set_height(height);
                member.set_weight(weight);
                std::cout << "Member details updated.\n";
                return;
            }
        }
        std::cout << "Could not find member with ID " << id << ".\n";
    }

    void display_all_members() const {
        if (members.empty()) {
            std::cout << "No members in the system yet.\n";
            return;
        }

        std::cout << "\n------ All Members ------\n";
        for (const auto& member : members) {
            member.display();
        }
    }

    void display_member_bmi(int id) const {
        for (const auto& member : members) {
            if (member.get_id() == id) {
                member.display();
                return;
            }
        }
        std::cout << "Could not find member with ID " << id << ".\n";
    }

    void display_statistics() const {
        if (members.empty()) {
            std::cout << "No members to generate stats for.\n";
            return;
        }

        std::cout << "\n------ Gym Statistics ------\n";
        std::cout << "Total members: " << members.size() << std::endl;
        
        double total_height = 0;
        double total_weight = 0;
        double max_h = members.front().get_height();
        double min_h = members.front().get_height();
        double max_w = members.front().get_weight();
        double min_w = members.front().get_weight();
        int max_h_id = members.front().get_id();
        int min_h_id = members.front().get_id();
        int max_w_id = members.front().get_id();
        int min_w_id = members.front().get_id();

        for (const auto& member : members) {
            total_height += member.get_height();
            total_weight += member.get_weight();

            if (member.get_height() > max_h) {
                max_h = member.get_height();
                max_h_id = member.get_id();
            }
            if (member.get_height() < min_h) {
                min_h = member.get_height();
                min_h_id = member.get_id();
            }
            if (member.get_weight() > max_w) {
                max_w = member.get_weight();
                max_w_id = member.get_id();
            }
            if (member.get_weight() < min_w) {
                min_w = member.get_weight();
                min_w_id = member.get_id();
            }
        }
        
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Average Height: " << (total_height / members.size()) << "m\n";
        std::cout << "Average Weight: " << (total_weight / members.size()) << "kg\n";
        std::cout << "Maximum Height: " << max_h << "m (Member ID: " << max_h_id << ")\n";
        std::cout << "Minimum Height: " << min_h << "m (Member ID: " << min_h_id << ")\n";
        std::cout << "Maximum Weight: " << max_w << "kg (Member ID: " << max_w_id << ")\n";
        std::cout << "Minimum Weight: " << min_w << "kg (Member ID: " << min_w_id << ")\n";
    }
};

void show_menu() {
    std::cout << "\n===== Gym Management System =====\n"
              << "1. Add Member\n"
              << "2. Remove Member\n"
              << "3. Update Member\n"
              << "4. Display All Members\n"
              << "5. Display Member BMI\n"
              << "6. Display Statistics\n"
              << "0. Exit\n"
              << "Enter your choice: ";
}

int main() {
    GymManagement gym;
    int choice;
    
    do {
        show_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

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
                gym.add_member(id, height, weight);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Member ID to remove: ";
                std::cin >> id;
                gym.remove_member(id);
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
                gym.update_member(id, height, weight);
                break;
            }
            case 4:
                gym.display_all_members();
                break;
            case 5: {
                int id;
                std::cout << "Enter Member ID to display BMI: ";
                std::cin >> id;
                gym.display_member_bmi(id);
                break;
            }
            case 6:
                gym.display_statistics();
                break;
            case 0:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Supporting Classes

class Diet {
private:
    string type;

public:
    Diet(const string& type) : type(type) {}
    string getType() const {
        return type;
    }
};

class Habitat {
private:
    string description;

public:
    Habitat(const string& description) : description(description) {}
    string getDescription() const {
        return description;
    }
};

// Abstract Base Class

class Animal {
protected:
    string name;
    int age;
    const string species;
    Diet diet;
    Habitat habitat;

public:
    Animal(const string& name, int age, const string& species, const Diet& diet, const Habitat& habitat)
        : name(name), age(age), species(species), diet(diet), habitat(habitat) {}

    virtual void makeSound() const = 0;
    virtual void eat() const = 0;
    virtual ~Animal() {}

    virtual void displayInfo() const final {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Species: " << species << endl;
        cout << "Diet Type: " << diet.getType() << endl;
        cout << "Habitat: " << habitat.getDescription() << endl;
        cout << "----------------------" << endl;
    }
};

// Derived Classes

class Giraffe : public Animal {
public:
    Giraffe(const string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Giraffe", diet, habitat) {}

    void makeSound() const override {
        cout << name << " hums gently." << endl;
    }

    void eat() const override {
        cout << name << " munches on leaves from tall trees." << endl;
    }
};

class Penguin : public Animal {
public:
    Penguin(const string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Penguin", diet, habitat) {}

    void makeSound() const override {
        cout << name << " squawks loudly." << endl;
    }

    void eat() const override {
        cout << name << " gulps down a fish." << endl;
    }
};

// Zoo Management Function

void makeAllAnimalsSound(const vector<Animal*>& zoo) {
    for (const auto& animal : zoo) {
        animal->makeSound();
    }
}

// Main Program

int main() {
    vector<Animal*> zoo;

    // Diets and Habitats
    Diet herbivore("Herbivore");
    Diet carnivore("Carnivore");
    Habitat savanna("African Savanna");
    Habitat arctic("Icy Antarctic Shores");

    // Create Giraffes
    Giraffe* g1 = new Giraffe("Sarah", 5, herbivore, savanna);
    Giraffe* g2 = new Giraffe("Melvin", 7, herbivore, savanna);

    // Create Penguins
    Penguin* p1 = new Penguin("Lani", 3, carnivore, arctic);
    Penguin* p2 = new Penguin("Cody", 4, carnivore, arctic);

    // Add animals to zoo
    zoo.push_back(g1);
    zoo.push_back(g2);
    zoo.push_back(p1);
    zoo.push_back(p2);

    // Demonstrate polymorphism
    cout << "Zoo Sounds:\n";
    makeAllAnimalsSound(zoo);

    // Display animal info
    cout << "\nAnimal Information:\n";
    for (const auto& animal : zoo) {
        animal->displayInfo();
    }

    // Clean up memory
    for (auto animal : zoo) {
        delete animal;
    }

    return 0;
}
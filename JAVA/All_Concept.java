// Define a parent class 'Animal'
class Animal {
    private String name;

    // Constructor
    public Animal(String name) {
        this.name = name;
    }

    // Encapsulation: Provide a getter method for 'name'
    public String getName() {
        return name;
    }

    // Abstraction: Define an abstract method 'makeSound'
    public void makeSound() {
        System.out.println("Animal makes a sound");
    }
}

// Inheritance: Create a subclass 'Dog' that extends 'Animal'
class Dog extends Animal {
    // Constructor
    public Dog(String name) {
        super(name);
    }

    // Polymorphism: Override the 'makeSound' method
    @Override
    public void makeSound() {
        System.out.println(getName() + " barks");
    }
}

// Inheritance: Create another subclass 'Cat' that extends 'Animal'
class Cat extends Animal {
    // Constructor
    public Cat(String name) {
        super(name);
    }

    // Polymorphism: Override the 'makeSound' method
    @Override
    public void makeSound() {
        System.out.println(getName() + " meows");
    }
}

public class OOPConceptsExample {
    public static void main(String[] args) {
        // Create objects of 'Dog' and 'Cat' classes
        Dog dog = new Dog("Buddy");
        Cat cat = new Cat("Whiskers");

        // Demonstrate polymorphism
        Animal[] animals = { dog, cat };
        for (Animal animal : animals) {
            animal.makeSound();
        }
    }
}

// Class and Object
class BankAccount {
    private String accountNumber;
    private double balance;

    //  Constructor
    public BankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
    }

    // Encapsulation (Getter method)
    public String getAccountNumber() {
        return accountNumber;
    }

    //  Encapsulation (Getter method)
    public double getBalance() {
        return balance;
    }

    //  Polymorphism (Method Overriding)
    @Override
    public String toString() {
        return "Account Number: " + accountNumber + "\nBalance: $" + balance;
    }

    //  Inheritance (Base class method)
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited $" + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    //  Inheritance (Base class method)
    public void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn $" + amount);
        } else {
            System.out.println("Insufficient balance or invalid withdrawal amount.");
        }
    }
}

 //Inheritance (Derived class)
class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(String accountNumber, double initialBalance, double interestRate) {
        super(accountNumber, initialBalance);
        this.interestRate = interestRate;
    }

    // Polymorphism (Method Overriding)
    @Override
    public String toString() {
        return super.toString() + "\nInterest Rate: " + interestRate + "%";
    }

    // Encapsulation (Getter method)
    public double getInterestRate() {
        return interestRate;
    }

    // Encapsulation (Setter method)
    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    // Custom method specific to SavingsAccount
    public void calculateInterest() {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest);
        System.out.println("Interest of $" + interest + " calculated and deposited.");
    }
}

public class BankDemo {
    public static void main(String[] args) {
        // Creating a savings account
        SavingsAccount savingsAccount = new SavingsAccount("SA12345", 1000.0, 3.5);

        // Polymorphism (Method Overriding)
        System.out.println(savingsAccount);

        // Inheritance (Base class method)
        savingsAccount.deposit(500.0);
        savingsAccount.withdraw(200.0);

        //  Encapsulation (Getter method)
        System.out.println("Updated Balance: $" + savingsAccount.getBalance());

        // Custom method specific to SavingsAccount
        savingsAccount.calculateInterest();

        // Polymorphism (Method Overriding)
        System.out.println(savingsAccount);
    }
}

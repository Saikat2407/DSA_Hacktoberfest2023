import os

def display_menu():
    print("Task Manager Menu:")
    print("1. Add Task")
    print("2. Remove Task")
    print("3. List Tasks")
    print("4. Mark Task as Completed")
    print("5. Exit")

def add_task(tasks, task):
    tasks.append(task)

def remove_task(tasks, task):
    if task in tasks:
        tasks.remove(task)
    else:
        print("Task not found!")

def list_tasks(tasks):
    if not tasks:
        print("No tasks found.")
    else:
        for index, task in enumerate(tasks):
            print(f"{index + 1}. {task}")

def mark_completed(tasks, task):
    if task in tasks:
        tasks.remove(task)
        completed_tasks.append(task)
    else:
        print("Task not found!")

def save_tasks(filename, tasks):
    with open(filename, "w") as file:
        for task in tasks:
            file.write(task + "\n")

def load_tasks(filename):
    tasks = []
    if os.path.exists(filename):
        with open(filename, "r") as file:
            tasks = [line.strip() for line in file]
    return tasks

def main():
    tasks = load_tasks("tasks.txt")
    completed_tasks = load_tasks("completed_tasks.txt")

    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            task = input("Enter the task: ")
            add_task(tasks, task)
        elif choice == "2":
            task = input("Enter the task to remove: ")
            remove_task(tasks, task)
        elif choice == "3":
            list_tasks(tasks)
        elif choice == "4":
            task = input("Enter the task to mark as completed: ")
            mark_completed(tasks, task)
        elif choice == "5":
            save_tasks("tasks.txt", tasks)
            save_tasks("completed_tasks.txt", completed_tasks)
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()

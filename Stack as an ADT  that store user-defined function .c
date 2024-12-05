#include<stdio.h>

#define MAX_SIZE 5 // Maximum capacity of stack

// Struct to store vehicle details
struct vehicle {
    char name[20];
    float cost;
};

// Stack structure to store vehicles
struct vehicle_stack {
    int top_index;
    struct vehicle stack[MAX_SIZE];
};

// Function to initialize the stack
void initStack(struct vehicle_stack *vs) {
    vs->top_index = -1;  // Set top of stack to -1 (empty)
}

// Function to push an element onto the stack
void pushVehicle(struct vehicle_stack *vs, struct vehicle v) {
    if (vs->top_index >= MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot add more vehicles.\n");
    } else {
        vs->stack[++(vs->top_index)] = v;  // Increment top_index and add the vehicle
    }
}

// Function to pop an element from the stack
struct vehicle popVehicle(struct vehicle_stack *vs) {
    struct vehicle v = {"", 0.0}; // Default empty vehicle

    if (vs->top_index == -1) {
        printf("Stack Underflow: No vehicles to remove.\n");
    } else {
        v = vs->stack[vs->top_index--]; // Get vehicle at top_index and decrement top_index
    }
    return v;
}

// Function to peek at the top element of the stack
struct vehicle peekVehicle(struct vehicle_stack *vs) {
    if (vs->top_index == -1) {
        printf("Stack Underflow: No vehicles to view.\n");
        return (struct vehicle){"", 0.0};  // Return default empty vehicle
    }
    return vs->stack[vs->top_index];  // Return the vehicle at the top
}

// Function to check if the stack is full
int isStackFull(struct vehicle_stack *vs) {
    return vs->top_index == MAX_SIZE - 1;  // Full if top_index is the last index
}

// Function to check if the stack is empty
int isStackEmpty(struct vehicle_stack *vs) {
    return vs->top_index == -1;  // Empty if top_index is -1
}

int main() {
    int option;
    struct vehicle v;
    struct vehicle_stack vs;

    initStack(&vs);  // Initialize the stack

    do {
        // Display menu options
        printf("\n1. Add Vehicle\n2. Remove Vehicle\n3. View Top Vehicle\n4. Check if Full\n5. Check if Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (isStackFull(&vs)) {
                    printf("Stack is full. Cannot add more vehicles.\n");
                } else {
                    printf("Enter vehicle name: ");
                    scanf("%s", v.name);  // Get vehicle name
                    printf("Enter vehicle cost: ");
                    scanf("%f", &v.cost);    // Get vehicle cost
                    pushVehicle(&vs, v);  // Push vehicle onto stack
                }
                break;

            case 2:
                if (isStackEmpty(&vs)) {
                    printf("Stack is empty. Cannot remove any vehicles.\n");
                } else {
                    v = popVehicle(&vs);  // Pop vehicle from stack
                    printf("Removed vehicle details:\n");
                    printf("Vehicle Name: %s\n", v.name);
                    printf("Vehicle Cost: %.2f\n", v.cost);
                }
                break;

            case 3:
                if (isStackEmpty(&vs)) {
                    printf("Stack is empty. No vehicles to view.\n");
                } else {
                    v = peekVehicle(&vs);  // Peek at the vehicle at the top
                    printf("Vehicle at the top:\n");
                    printf("Vehicle Name: %s\n", v.name);
                    printf("Vehicle Cost: %.2f\n", v.cost);
                }
                break;

            case 4:
                if (isStackFull(&vs)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;

            case 5:
                if (isStackEmpty(&vs)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option (1-6).\n");
                break;
        }
    } while (option != 6);

    return 0;
}

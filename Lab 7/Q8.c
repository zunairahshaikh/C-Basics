#include <stdio.h>

int main() {
    char expression[100]; 
    int result = 0;
    int current_number = 0;
    char last_operator = '+'; 
    int i = 0;
    printf("Enter an expression (e.g., 20+10-30): ");
    scanf("%s", expression); // Read the expression as a string

    
    for (i = 0; expression[i] != '\0'; i++) {
        char char_current = expression[i];
        if (char_current >= '0' && char_current <= '9') {
            current_number = current_number * 10 + (char_current - '0'); 
        } 
        else if (char_current == '+' || char_current == '-') {
            if (current_number == 0 && (last_operator == '+' || last_operator == '-')) {
                printf("Invalid expression\n");
                return 1;
            }

          
            if (last_operator == '+') {
                result += current_number;
            } else if (last_operator == '-') {
                result -= current_number;
            }

            // Update the last operator and reset current number
            last_operator = char_current;
            current_number = 0; // Reset current number
        }
    }

    // Handle the last number after the loop
    if (last_operator == '+' || last_operator == '-') {
        if (current_number == 0 && (last_operator == '+' || last_operator == '-')) {
            printf("Invalid expression\n");
            return 1;
        }

        if (last_operator == '+') {
            result += current_number;
        } else if (last_operator == '-') {
            result -= current_number;
        }
    }  
    printf("Result: %d\n", result);
    return 0;
}

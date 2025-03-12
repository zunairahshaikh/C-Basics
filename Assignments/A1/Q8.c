#include <stdio.h>
#include <string.h>

int BinaryToDecimal(int binary);
int DecimalToBinary(int decimalNumber);
void DecimalToHexadecimal(int decimalNumber);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int binary);
void HexadecimalToBinary(char hexNumber[]);

int main() {
    int choice, binary, decimal;
    char hex[100];

    while (1) {
        printf("\n Conversion Menu \n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                int decimalResult = BinaryToDecimal(binary);
                if (decimalResult == -1)
                    printf("Invalid binary number.\n");
                else
                    printf("Decimal value: %d\n", decimalResult);
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                int binaryResult = DecimalToBinary(decimal);
                if (binaryResult == -1)
                    printf("Invalid input. Enter a non-negative integer.\n");
                else
                    printf("Binary value: %d\n", binaryResult);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Hexadecimal value: ");
                DecimalToHexadecimal(decimal);
                printf("\n");
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                printf("Decimal value: ");
                HexadecimalToDecimal(hex);
                printf("\n");
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &binary);
                printf("Hexadecimal value: ");
                BinaryToHexadecimal(binary);
                printf("\n");
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                printf("Binary value: ");
                HexadecimalToBinary(hex);
                printf("\n");
                break;

            case 7:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
}

int BinaryToDecimal(int binary){
    int decimalValue = 0, base = 1, lastDigit;

    while (binary > 0) {
        lastDigit = binary % 10;
        if (lastDigit != 0 && lastDigit != 1) {
            return -1;
        }
        
        decimalValue += lastDigit * base;
        base*= 2;
        binary/= 10;
    }

    return decimalValue;   
}

int DecimalToBinary(int decimalNumber){
    if (decimalNumber < 0) {
        return -1;
    }
    int rem, binary =0, base=1;

    while (decimalNumber > 0) {
        rem = decimalNumber % 2;
        binary += rem * base;
        base *= 10;
        decimalNumber/= 2;
    }

    return binary;
}

void DecimalToHexadecimal(int decimalNumber){
    if (decimalNumber < 0) {
        printf("Invalid input. Please enter a non-negative integer.");
        printf("\n");
        return; // invalid input return
    }

    char hex[100];
    int index = 0, rem;

    do {
        rem = decimalNumber % 16;
        if (rem < 10) {
            hex[index] = 48 + rem; // ASCII value for numbers
        } else {
            hex[index] = 55 + rem; // ASCII value for A-F
        }
        index++;
        decimalNumber/= 16;
    }
    while (decimalNumber != 0);

    printf("The hexadecimal representation is: ");
    for (int i = index - 1; i >= 0; i--) { //printing in reverse
        printf("%c", hex[i]);
    }
}
void HexadecimalToDecimal(char hexNumber[]){
    int length = strlen(hexNumber);
    strupr(hexNumber);
    int decimalValue = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--) { //going in reverse order
        char currentChar = hexNumber[i]; 

        if (currentChar >= '0' && currentChar <= '9') {
            decimalValue += (currentChar - '0') * base;
        }
        else if (currentChar >= 'A' && currentChar <= 'F') {
            decimalValue += (currentChar - 'A' + 10) * base;
        }
        else {
            printf("Invalid hexadecimal input.\n");
            return;
        }

        base *= 16;
    }

    printf("The decimal value is: %d", decimalValue);
}

void BinaryToHexadecimal(int binary){
    int decimal;
    decimal = BinaryToDecimal(binary);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]){
    int length = strlen(hexNumber);
    int decimalValue = 0,base = 1, binary;
    strupr(hexNumber);

    for (int i = length - 1; i >= 0; i--) {
        char currentChar = hexNumber[i];

        if (currentChar >= '0' && currentChar <= '9') {
            decimalValue += (currentChar - '0') * base;
        }
        else if (currentChar >= 'A' && currentChar <= 'F') {
            decimalValue += (currentChar - 'A' + 10) * base;
        }
        else {
            printf("Invalid hexadecimal input.");
            return;
        }

        base *= 16;
    }
    
    binary = DecimalToBinary(decimalValue);
    printf("The binary value is: %d", binary);
}
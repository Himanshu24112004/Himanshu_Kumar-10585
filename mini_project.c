#include <stdio.h>
#include<math.h>

// function for finding  desired power of a number .

long long power_ll(long long base, int exp) {
    long long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;   // repeated multiplication
    }
    return result;
}

//function for finding factorial of a number 
unsigned long long factorial_ull(unsigned int n) {
    unsigned long long fact = 1;
    for (unsigned int i = 1; i <= n; i++) fact *= i;   // loop factorial method
    return fact;
}

int main(void) {
    int choice;
    char again;

    do {
        //Choices of operation, we wanted to perform (from 1 to 11)    
        printf("\n===== Menu-Driven Scientific Calculator =====\n");
        printf("1. Addition (a + b)\n");
        printf("2. Subtraction (a - b)\n");
        printf("3. Multiplication (a * b)\n");
        printf("4. Division (a / b)\n");
        printf("5. Modulus (a %% b)\n");
        printf("6. Square (n^2)\n");
        printf("7. Cube   (n^3)\n");
        printf("8. Power  (base^exponent)\n");
        printf("9. Square root (sqrt(x))\n");
        printf("10. Factorial (n!)\n");
        printf("11. Exit\n");

        printf("Enter your choice (1-11): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            
            //  For Addition operation 
            case 1: {
                double a, b;
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.4lf + %.4lf = %.4lf\n", a, b, a + b);
                break;
            }

            //For Subtraction operation
            case 2: {
                double a, b;
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.4lf - %.4lf = %.4lf\n", a, b, a - b);
                break;
            }

            //For multiplication operation
            case 3: {
                double a, b;
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.4lf * %.4lf = %.4lf\n", a, b, a * b);
                break;
            }

            //For Division operation
            case 4: {
                double a, b;
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);

                // division-by-zero handling 
                if (b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("%.4lf / %.4lf = %.4lf\n", a, b, a / b);
                }
                break;
            }

            //For Modulus operation  i.e., remainder on division of to numbers 
            case 5: {
                long long a, b;
                printf("Enter two integers: ");
                scanf("%lld %lld", &a, &b);

                //division by zero handling 
                if (b == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    printf("%lld %% %lld = %lld\n", a, b, a % b);
                }
                break;
            }

            //For squaring a number
            case 6: {
                long long n;
                printf("Enter number: ");
                scanf("%lld", &n);
                printf("Square of %lld = %lld\n", n, n * n);
                break;
            }

            //For finding cube of a number 
            case 7: {
                long long n;
                printf("Enter number: ");
                scanf("%lld", &n);
                printf("Cube of %lld = %lld\n", n, n * n * n);
                break;
            }

            //For finding desired power of a number 
            case 8: {
                long long base;
                int exp;
                printf("Enter base: ");
                scanf("%lld", &base);
                printf("Enter exponent (non-negative integer): ");
                scanf("%d", &exp);

                //for ensuring that exponent is non-negative 
                if (exp < 0) {
                    printf("Exponent must be non-negative (this version uses loop multiplication).\n");
                } else {
                    long long ans = power_ll(base, exp);// power_ll function called here 
                    printf("%lld ^ %d = %lld\n", base, exp, ans);
                }
                break;
            }

            // For finding square root a number 
            case 9: {
                double x;
                printf("Enter number (>= 0): ");
                scanf("%lf", &x);

                // For handling that number is non-negative
                if (x < 0) {
                    printf("Square root is not defined for negative numbers in real numbers.\n");
                } else {
                    printf("sqrt(%.4lf) = %.4lf\n", x, sqrt(x));
                }
                break;
            }

            //For finding factorial of a number 
            case 10: {
                unsigned int n;
                printf("Enter a non-negative integer: ");
                scanf("%u", &n);

                // Note: even unsigned long long overflows after some n (commonly after 20!)
                printf("%u! = %llu\n", n, factorial_ull(n));
                break;
            }

            //An optional choice for exiting from operation if you don't need any calculation  
            case 11:
                printf("Exiting...\n");
                return 0;
           
            default:
                printf("Wrong choice. Please select 1-11.\n");
        }    

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &again);  // space before %c consumes newline
    } while (again == 'y' || again == 'Y');// looping if user wanting to perform any other calculation...

    printf("Program ended.\n"); 
    return 0;
}

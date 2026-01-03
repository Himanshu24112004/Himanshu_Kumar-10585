#include <stdio.h>

long long power_ll(long long base, int exp) {
    long long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;   // repeated multiplication
    }
    return result;
}

int main(void) {
    int choice;
    char again;

    do {
        printf("\n===== Menu-Driven Scientific Calculator =====\n");
        printf("1. Square (n^2)\n");
        printf("2. Cube   (n^3)\n");
        printf("3. Power  (base^exponent)\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1: {
                long long n;
                printf("Enter number: ");
                scanf("%lld", &n);
                printf("Square of %lld = %lld\n", n, n * n);
                break;
            }
            case 2: {
                long long n;
                printf("Enter number: ");
                scanf("%lld", &n);
                printf("Cube of %lld = %lld\n", n, n * n * n);
                break;
            }
            case 3: {
                long long base;
                int exp;
                printf("Enter base: ");
                scanf("%lld", &base);
                printf("Enter exponent (non-negative integer): ");
                scanf("%d", &exp);

                if (exp < 0) {
                    printf("Exponent must be non-negative (this version uses loop multiplication).\n");
                } else {
                    long long ans = power_ll(base, exp);
                    printf("%lld ^ %d = %lld\n", base, exp, ans);
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Wrong choice. Please select 1-4.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &again);  // space before %c consumes newline
    } while (again == 'y' || again == 'Y');

    printf("Program ended.\n");
    return 0;
}

#include <stdio.h>
#include <math.h>

double CompoundInterest(double principal, double rate, int time) {
    int n = 1;
    double r = rate / 100.0;
    double futureValue = principal * pow(1 + (r / n), n * time);
    double interest = futureValue - principal;
    
    return interest;
}

int main() {
    double principal, rate, compoundInterest;
    int time;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter the time period (in years): ");
    scanf("%d", &time);

    // Call the function to calculate compound interest
    compoundInterest = CompoundInterest(principal, rate, time);

    printf("Compound Interest: %.2lf\n", compoundInterest);

    return 0;
}

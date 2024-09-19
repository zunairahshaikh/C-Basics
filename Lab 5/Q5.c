#include <stdio.h>

int main() {
  float gpa;
  printf("Enter gpa: ");
  scanf("%f", &gpa);
  gpa>=0.0 && gpa<= 0.99? printf("failed semester - registration suspended") :
  gpa>= 1.0 && gpa <2.0? printf("on probation for next semester"):
  gpa>=2.0 && gpa < 3.0? printf(" "):
  gpa>=3.0 && gpa < 3.5? printf("Dean's list for semester"):
  printf("Highest honours for semester");;;;
}

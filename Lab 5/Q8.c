#include <stdio.h>

int main() {
  int rollnum,regyear, sem;
  char semType, section;
  
  printf("Enter roll number: ");
  scanf("%d", &rollnum);
  
  // assuming the user would input the correct roll number the second time
  if(rollnum > 999999){
      printf("More than six digits. Re enter roll num");
      scanf("%d", &rollnum);
  }
  else if (rollnum <99999){
      printf("less than six digits. Re enter roll num");
      scanf("%d", &rollnum);
  }
  
  regyear = rollnum/10000;
  
  //cuurent year is 2024
  if(regyear > 24){
      printf("Invalid input");
      return 0;
  }
   //assuming there are 2 semesters, spring anbd fall
   printf("Which semester is it? enter 's' for spring, 'f' for fall: ");
   scanf(" %c", &semType);
   
  sem = regyear == 21? 
            semType == 'f'? 7:8
        :regyear == 22?
            semType == 'f'? 5:6
        :regyear == 23?
            semType == 'f'? 3:4
        :regyear == 24?
            semType == 'f'? 1:2
        :9;
if(sem>8){
    printf("already graduated");
    return 0;
}

section = (rollnum/1000)%10 == 1? 'A'
            :(rollnum/1000)%10 == 2? 'B'
            :(rollnum/1000)%10 == 3? 'C'
            :(rollnum/1000)%10 == 4? 'D'
            :(rollnum/1000)%10 == 5? 'E'
            :(rollnum/1000)%10 == 6? 'F'
            :(rollnum/1000)%10 == 7? 'G'
            :(rollnum/1000)%10 == 8? 'H'
            :'J';
            
    printf("Year of registeration: %d \nSemester: %d \nSection: %c", regyear, sem, section);
    return 0;
}

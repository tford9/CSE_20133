#include <stdio.h>
#include <stdlib.h>

struct Student
{
  char letter_grade;
  int student_id;
  int age;
} Student;

int main(int argc, char const *argv[]) {

  //struct Student student1 = {0, 'A', 1234};

    printf("Size of char is: %d\n", sizeof(char));

    printf("Size of struct Student is:%d\n", sizeof(struct Student));


  return 0;
}

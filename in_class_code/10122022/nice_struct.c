#include <stdio.h>

typedef struct Student
{
  int age;
  char letter_grade;
  int student_id;
} Student;

int main(int argc, char const *argv[]) {
  Student student1 = {0, 'A', 1234};
  printf("The student with ID: %d has the letter grade %c\n", student1.student_id, student1.letter_grade);
  return 0;
}

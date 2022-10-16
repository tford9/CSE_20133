#include <stdio.h>
#include <stdlib.h>

struct Student
{
  char letter_grade;
  int age;
  int student_id;
} Student;

int main(int argc, char const *argv[]) {

  struct Student student1 = {0, 'A', 1234};

  printf("The address of the struct and its elements:\n");
  printf("&student1 %p\n", &student1);
  printf("&student1.age %p\n", &student1.age);
  printf("&student1.letter_grade %p\n", &student1.letter_grade);
  printf("&student1.student_id %p\n", &student1.student_id);

  return 0;

}

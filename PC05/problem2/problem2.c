#include "stdio.h"
#include "stdlib.h"

typedef unsigned int uint;

struct Student
{
  // add the definition of the struct
};

/* This function accepts an array of struct Student structs and an integer
cohort_year and returns an array of students with a admit_year that matches.*/
void cohort_finder(struct Student *, uint, uint);

void student_lookup(struct Student *, uint, uint);

void print_student_record(struct Student);

int main(int argc, char const *argv[]) {

  struct Student student_roster[100];

  struct Student s;

  s.name = "Test Student";
  s.department = "Engineering";
  s.course = "N/A";
  s.admit_year = 2009;
  s.id = 0001;

  student_roster[0] = s;

  printf("Performing Cohort Finder for Year: 2009\n");
  cohort_finder(student_roster,1, 2009);

  printf("Performing Student Lookup for id: 0001\n");
  student_lookup(student_roster, 1, 0001);

  return 0;
}

void student_lookup(struct Student students[], uint n, uint id)
{
  struct Student matching_student;

  /* YOUR CODE GOES HERE!
    Complete the student ID lookup function such that it prints the matching
    student's record. The printing code already exists.
  */

  printf("Matching Student Is:\n");
  print_student_record(matching_student);
}

void cohort_finder(struct Student students[], uint n, uint cohort_year)
{

  // create an oversized array on the heap to contain the matching students
  struct Student * cohort_students = (struct Student*)malloc(sizeof(struct Student)*n);

  // j is the counter for the matching students
  uint j = 0;

  /* YOUR CODE GOES HERE!
    Your code should find the matching students in the struct Student array and
    add them to a new array (cohort_students).
  */

  // resize the heap allocation so the size can be determined using sizeof
  cohort_students = (struct Student*)realloc(cohort_students, j*sizeof(struct Student));

  // check if the pointer is null
  if(cohort_students == NULL)
  {
    printf("Something Went Wrong During Allocation of cohort_students\n");
  }

  printf("The Students from %d Are:\n", cohort_year);
  for(uint i=0; i<j; i++)
  {
    print_student_record(cohort_students[i]);
  }
}

void print_student_record(struct Student student)
{
  printf("\n");
  printf("Student Name: %s\n", student.name);
  printf("Student department: %s\n", student.department);
  printf("Student course: %s\n", student.course);
  printf("Student admit_year: %d\n", student.admit_year);
  printf("Student id: %d\n", student.id);
  printf("\n");
}

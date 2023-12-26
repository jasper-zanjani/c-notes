#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[20];
    float midterm1;
    float midterm2;
    float final_exam;
    float final_grade;
} Student;

int main(void)
{
    printf("Let's grade!\n");
    Student alvin, bob, charlie;

    strcpy(alvin.name, "Alvin");
    strcpy(bob.name, "Bob");
    strcpy(charlie.name, "Charlie");

    alvin.midterm1 = 90;
    alvin.midterm2 = 96;
    alvin.final_exam = 88;

    bob.midterm1 = 86;
    bob.midterm2 = 74;
    bob.final_exam = 98;

    charlie.midterm1 = 89;
    charlie.midterm2 = 93;
    charlie.final_exam = 90;

    alvin.final_grade = (alvin.midterm1 + alvin.midterm2 + alvin.final_exam) / 3;
    bob.final_grade = (bob.midterm1 + bob.midterm2 + bob.final_exam) / 3;
    charlie.final_grade = (charlie.midterm1 + charlie.midterm2 + charlie.final_exam) / 3;

    printf("%s's final grade is %2.1f\n", alvin.name, alvin.final_grade);
    printf("%s's final grade is %2.1f\n", bob.name, bob.final_grade);
    printf("%s's final grade is %2.1f\n", charlie.name, charlie.final_grade);

    return 0;
}

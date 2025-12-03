#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

int main() {
   /* Student s(0, "Csaba", "Kazan");

    s.addGrade("Roman", 8);
    s.addGrade("Matek", 5);
    s.addGrade("Magyar", 10);
    s.addGrade("Kemia", 10);
    s.computeAverage();
    cout<<s;
    GraduationDao gr(2025);
    gr.enrollStudents("students.txt");
    gr.readGradesSubject("Romanian", "romanian.txt");
    gr.readGradesSubject("Hungarian", "hungarian.txt");
    gr.readGradesSubject("Math", "math.txt");*/
    string subjects[]{"math", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    GraduationDao dao(2023);
    dao.enrollStudents("students.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    return 0;
}
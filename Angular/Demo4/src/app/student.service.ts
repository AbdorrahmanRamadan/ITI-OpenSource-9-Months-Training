import { Injectable } from '@angular/core';
import { Student } from './_models/student';

@Injectable({
  providedIn: 'root'
})
export class StudentService {

  private students:Student[] = [
    new Student(1,"Ahmed",24,2),
    new Student(2,"Hazem",23,2),
    new Student(3,"Mohamed",22,2),
  ];

  getAllStudents(){
    return this.students;
  }

  addStudent(newStudent:Student){
    this.students.push(new Student(newStudent.id, newStudent.name, newStudent.age, newStudent.deptno));
  }
  constructor() { }
}

import { Component, OnInit } from '@angular/core';
import { Student } from 'src/app/_models/student.model';

@Component({
  selector: 'app-student',
  templateUrl: './student.component.html',
  styleUrls: ['./student.component.css']
})
export class StudentComponent implements OnInit {
  student: Student = new Student(0, '', 0, 0);
  students: Student[] = [];
  setID(ID: string): void {
    this.student.ID = Number(ID);
  }
  setName(Name: string): void {
    this.student.Name = Name;
  }
  setAge(Age: string): void {
    this.student.Age = Number(Age);
  }
  setDept(Dept_Number: string): void {
    this.student.Dept_Number = Number(Dept_Number);
  }
  add(ID: string, Name: string, Age: string, Dept_Number: string): void {
    let student = new Student(0, '', 0, 0);
    student.ID = Number(ID);
    student.Name = Name;
    student.Age = Number(Age);
    student.Dept_Number = Number(Dept_Number);
    this.students.push(student);
  }

  delete(index:number):void{
    this.students.splice(index,1)
  }
  edit(ID: string, Name: string, Age: string, Dept_Number: string, index: number): void{
    console.log(index);
    this.students[index].ID=Number(ID);
    this.students[index].Name=Name;
    this.students[index].Age=Number(Age);
    this.students[index].Dept_Number=Number(Dept_Number);
  }
  getSudentCount(): number {
    return this.students.length;
  }
  ngOnInit(): void {
  }

}

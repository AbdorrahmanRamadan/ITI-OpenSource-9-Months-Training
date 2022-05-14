import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { StudentService } from 'src/app/student.service';
import { Student } from 'src/app/_models/student';

@Component({
  selector: 'app-student-details',
  templateUrl: './student-details.component.html',
  styleUrls: ['./student-details.component.css']
})
export class StudentDetailsComponent implements OnInit {

  student:Student|null = new Student(0,"",0,0);

  constructor(public ac:ActivatedRoute, public std:StudentService) { }

  ngOnInit(): void {
    this.student = this.std.getStudent(this.ac.snapshot.params['id']);
  }

}

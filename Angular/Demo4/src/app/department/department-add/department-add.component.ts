import { Component, OnInit } from '@angular/core';
import { DepartmentService } from 'src/app/department.service';
import { Department } from 'src/app/_models/department';

@Component({
  selector: 'app-department-add',
  templateUrl: './department-add.component.html',
  styleUrls: ['./department-add.component.css']
})
export class DepartmentAddComponent implements OnInit {

  newDept:Department = new Department(0,"","");

  constructor(public deptSv:DepartmentService) { }

  insert(){
    this.deptSv.addDepartment(this.newDept);
  }

  ngOnInit(): void {
  }

}

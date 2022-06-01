import { Component, OnInit } from '@angular/core';
import { DepartmentService } from 'src/app/department.service';
import { Department } from 'src/app/_models/department.model';

@Component({
  selector: 'app-department-add',
  templateUrl: './department-add.component.html',
  styleUrls: ['./department-add.component.css'],
  // providers:[DepartmentService]
})
export class DepartmentAddComponent implements OnInit {
deptToAdd:Department= new Department(0,"","");
  constructor(public deptServ:DepartmentService) { }
  add(){
    console.log(this.deptToAdd.name)
    this.deptServ
      .addDepartment(this.deptToAdd)
      .subscribe((a) => this.deptServ.getAllDepartmets());
  }
  ngOnInit(): void {
  
  }

}

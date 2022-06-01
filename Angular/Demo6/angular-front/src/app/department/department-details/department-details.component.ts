import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { DepartmentService } from 'src/app/department.service';
import { Department } from 'src/app/_models/department.model';

@Component({
  selector: 'app-department-details',
  templateUrl: './department-details.component.html',
  styleUrls: ['./department-details.component.css'],
})
export class DepartmentDetailsComponent implements OnInit {
  constructor(
    private acRoute: ActivatedRoute,
    private depServ: DepartmentService,
    private router: Router
  ) {}

  deptToShow: Department = new Department(0, '', '');
  id = -1;
  ngOnInit(): void {
    this.acRoute.params.subscribe((param) => {
      this.depServ
        .getDepartmanet(param['id'])
        .subscribe((data) => (this.deptToShow = data));
    });
  }
  goHome() {
    this.router.navigate(['departments']);
  }
}

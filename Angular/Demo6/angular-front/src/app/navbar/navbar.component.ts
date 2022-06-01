import { Component, OnInit } from '@angular/core';
import { DepartmentService } from '../department.service';

@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent implements OnInit {
errors:boolean=false;
  constructor(private depServ:DepartmentService) { }

  ngOnInit(): void {
    this.errors = this.depServ.error  }

}

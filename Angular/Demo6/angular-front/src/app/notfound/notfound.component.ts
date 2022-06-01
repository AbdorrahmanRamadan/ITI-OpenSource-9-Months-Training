import { Component, OnInit } from '@angular/core';
import { DepartmentService } from '../department.service';

@Component({
  selector: 'app-notfound',
  templateUrl: './notfound.component.html',
  styleUrls: ['./notfound.component.css']
})
export class NotfoundComponent implements OnInit {

  constructor(private depServ:DepartmentService) { }

  ngOnInit(): void {
    this.depServ.error=true;
  }

}

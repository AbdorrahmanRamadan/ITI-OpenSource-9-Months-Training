import { Component, OnInit } from '@angular/core';


@Component({
  selector: 'app-test-prim-ng',
  templateUrl: './test-prim-ng.component.html',
  styleUrls: ['./test-prim-ng.component.css']
})
export class TestPrimNgComponent implements OnInit {

  date:Date = new Date();
  knob:number = 50;
  switch:boolean = false;
  slider:number = 50;
  checked:boolean = true;
  value:any;

  constructor() { }

  ngOnInit(): void {
  }

}

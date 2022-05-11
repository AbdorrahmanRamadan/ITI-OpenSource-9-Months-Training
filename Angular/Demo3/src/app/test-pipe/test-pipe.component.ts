import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-test-pipe',
  templateUrl: './test-pipe.component.html',
  styleUrls: ['./test-pipe.component.css']
})
export class TestPipeComponent implements OnInit {

  testPower:number = 5;
  testString:string = "Abdorrahman-Mohammad-Ahmad-Ramadan";
  query:string = "";
  testArray:string[] = ["Abdorrahman","Mohammad","Ahmad","Ramadan"];

  constructor() { }

  ngOnInit(): void {
  }

}

import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'app-rate',
  templateUrl: './rate.component.html',
  styleUrls: ['./rate.component.css']
})
export class RateComponent implements OnInit {

  @Input() rating= 1.45;
  cwidth = 0;
  constructor() { 
    this.cwidth = this.rating*15;
  }

  ngOnChanges(){
    this.cwidth = this.rating*15/20;
  }

  ngOnInit(): void {
  }

}

import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { StudentComponent } from './student/student.component';



@NgModule({
  declarations: [
    StudentComponent
  ],
  exports: [
    StudentComponent
  ],
  imports: [
    CommonModule
  ]
})
export class StudentModule { }

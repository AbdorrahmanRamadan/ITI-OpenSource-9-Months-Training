import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { StudentAddComponent } from './student-add/student-add.component';
import { StudentListComponent } from './student-list/student-list.component';
import { FormsModule } from '@angular/forms';
import { RouterModule, Routes } from '@angular/router';
import { StudentDetailsComponent } from './student-details/student-details.component';

const routs:Routes=[
  {path:"",component:StudentListComponent,
  children:[
    {path:"details/:id", component:StudentDetailsComponent}
  ]
},
  {path:"add",component:StudentAddComponent},
]

@NgModule({
  declarations: [
    StudentAddComponent,
    StudentListComponent,
    StudentDetailsComponent
  ],
  imports: [
    CommonModule,FormsModule,RouterModule.forChild(routs),
  ],
  exports: [StudentAddComponent, StudentListComponent]
})

export class StudentModule { }
import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DepartmentAddComponent } from './department-add/department-add.component';
import { DepartmentListComponent } from './department-list/department-list.component';
import { FormsModule } from '@angular/forms';
import { RouterModule, Routes } from '@angular/router';
import { DepartmentDetailsComponent } from './department-details/department-details.component';

const routs:Routes=[
  {path:"",component:DepartmentListComponent,
  children:[
    {path:"details/:id", component:DepartmentDetailsComponent}
  ]
},
  {path:"add",component:DepartmentAddComponent},
]

@NgModule({
  declarations: [
    DepartmentAddComponent,
    DepartmentListComponent,
    DepartmentDetailsComponent
  ],
  imports: [
    CommonModule, FormsModule, RouterModule.forChild(routs),
  ],
  exports: [DepartmentAddComponent, DepartmentListComponent]
})

export class DepartmentModule { }
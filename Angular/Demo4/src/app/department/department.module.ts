import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DepartmentAddComponent } from './department-add/department-add.component';
import { DepartmentListComponent } from './department-list/department-list.component';
import { FormsModule } from '@angular/forms';



@NgModule({
  declarations: [
    DepartmentAddComponent,
    DepartmentListComponent
  ],
  imports: [
    CommonModule, FormsModule
  ],
  exports: [DepartmentAddComponent, DepartmentListComponent]
})
export class DepartmentModule { }

import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DepartmentListComponent } from './department-list/department-list.component';
import { DepartmentAddComponent } from './department-add/department-add.component';
import { DepartmentDetailsComponent } from './department-details/department-details.component';
import { FormsModule } from '@angular/forms';
import { RouterModule, Routes } from '@angular/router';

const departmentRoutes:Routes = [{
  path: '',
  component: DepartmentListComponent,
  children: [{ path: 'add', component: DepartmentAddComponent }],
},
{ path: ':id', component: DepartmentDetailsComponent },]

@NgModule({
  declarations: [
    DepartmentListComponent,
    DepartmentAddComponent,
    DepartmentDetailsComponent,
  ],
  imports: [CommonModule, FormsModule, RouterModule.forChild(departmentRoutes)],
  exports: [
    DepartmentListComponent,
    DepartmentAddComponent,
    DepartmentDetailsComponent,
  ],
})
export class DepartmentModule {}

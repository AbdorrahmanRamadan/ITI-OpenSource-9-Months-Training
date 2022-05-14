import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { NavbarComponent } from './core/navbar/navbar.component';
import { HomeComponent } from './home/home.component';

const routes: Routes = [
  {path:"", component:HomeComponent},
  {path:"students", loadChildren:()=>import("./student/student.module").then(m=>m.StudentModule)},
  {path:"departments", loadChildren:()=>import("./department/department.module").then(m=>m.DepartmentModule)}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

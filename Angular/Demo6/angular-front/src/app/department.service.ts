import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Department } from './_models/department.model';

@Injectable({
  providedIn: 'root',
})
export class DepartmentService {
  public error = false;
  private deps: Department[] = [
    new Department(100, 'os', 'alex'),
    new Department(102, 'pd', 'alex'),
    new Department(101, 'os', 'cairo'),
    new Department(103, 'os', 'aswan'),
    new Department(105, 'Ai', 'alex'),
  ];
  private url: string = 'http://localhost:8000/departments/';
  getAllDepartmets() {
    return this.http.get<Department[]>(this.url);
  }
  addDepartment(dept: Department) {
    return this.http.post<Department>(this.url, dept);
  }
  getDepartmanet(id: number) {
    return this.http.get<Department>(this.url + id);
  }
  deleteDepartment(id: number) {
    return this.http.delete<Department>(this.url + id);
  }
  constructor(private http: HttpClient) {}
}

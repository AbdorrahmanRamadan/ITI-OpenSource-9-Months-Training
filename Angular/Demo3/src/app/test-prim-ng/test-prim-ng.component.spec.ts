import { ComponentFixture, TestBed } from '@angular/core/testing';

import { TestPrimNgComponent } from './test-prim-ng.component';

describe('TestPrimNgComponent', () => {
  let component: TestPrimNgComponent;
  let fixture: ComponentFixture<TestPrimNgComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ TestPrimNgComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(TestPrimNgComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

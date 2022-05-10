import { Department } from './department.model';

describe('Department', () => {
  it('should create an instance', () => {
    // @ts-ignore
    expect(new Department()).toBeTruthy();
  });
});

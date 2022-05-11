import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'convertString'
})
export class ConvertStringPipe implements PipeTransform {

  transform(value: string): unknown {
    return value.replace(/-/g," ");
  }

}

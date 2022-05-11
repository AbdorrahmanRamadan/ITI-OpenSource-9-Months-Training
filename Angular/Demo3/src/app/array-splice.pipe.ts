import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'arraySplice',
  pure: false,
})
export class ArraySplicePipe implements PipeTransform {

  transform(values: string[], forSearch:string): string[] {
    let ret:string[] = [];

    if(!forSearch){
      return values;
    }else{
      for (let i = 0; i < values.length; i++) {
        if(values[i].toLowerCase().includes(forSearch.toLowerCase())){
          ret.push(values[i]);
        }
      }
      return ret;
    }
  }
}

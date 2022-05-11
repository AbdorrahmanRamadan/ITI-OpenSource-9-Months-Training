import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { ProductComponent } from './product/product.component';
import { FormsModule } from '@angular/forms';
import { SharedModule } from '../shared/shared.module';
import { SearchPipe } from './search.pipe';
import { ConvertStringPipe } from './convert-string.pipe';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {CalendarModule} from 'primeng/calendar';
import {SliderModule} from 'primeng/slider';

@NgModule({
  declarations: [
    ProductComponent,SearchPipe,ConvertStringPipe
  ],
  imports: [
    CommonModule, FormsModule, SharedModule,BrowserAnimationsModule,CalendarModule,
    SliderModule,
  ],
  exports: [ProductComponent]
})
export class ProductModule {
}

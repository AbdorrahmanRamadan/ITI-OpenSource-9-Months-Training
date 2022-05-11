import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { PowerToxPipe } from './power-tox.pipe';
import { TestPipeComponent } from './test-pipe/test-pipe.component';
import { StringConvertPipe } from './string-convert.pipe';
import { ArraySplicePipe } from './array-splice.pipe';
import { FormsModule } from '@angular/forms';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import { TestPrimNgComponent } from './test-prim-ng/test-prim-ng.component';
import {CalendarModule} from 'primeng/calendar';
import {KnobModule} from 'primeng/knob';
import {InputSwitchModule} from 'primeng/inputswitch';
import {SliderModule} from 'primeng/slider';
import {TriStateCheckboxModule} from 'primeng/tristatecheckbox';
import { ProductModule } from "./product/ProductModule";


@NgModule({
  declarations: [
    AppComponent,
    PowerToxPipe,
    TestPipeComponent,
    StringConvertPipe,
    ArraySplicePipe,
    TestPrimNgComponent,    
  ],
  imports: [
    BrowserModule, FormsModule, BrowserAnimationsModule, CalendarModule, KnobModule,
    InputSwitchModule, SliderModule, TriStateCheckboxModule, ProductModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

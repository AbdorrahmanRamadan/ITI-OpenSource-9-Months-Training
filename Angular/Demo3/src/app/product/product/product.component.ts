import { Component, OnInit } from '@angular/core';
import { Product } from 'src/app/_model/product';

@Component({
  selector: 'app-product',
  templateUrl: './product.component.html',
  styleUrls: ['./product.component.css']
})
export class ProductComponent implements OnInit {

  newProduct:Product = new Product("", "", new Date(), "",0);
  viewProduct:Product = new Product("", "", new Date(), "",0);
  editProduct:Product = new Product("", "", new Date(), "",0);

  products:Product[] = [
    new Product("juice","gdn-0012",new Date("2020-2-2"),"20",95)
  ];
  query:string = "";
  constructor() { }

  ngOnInit(): void {
  }

  insert(){
    this.products.push(new Product(this.newProduct.name,this.newProduct.code,this.newProduct.available,this.newProduct.price,this.newProduct.rating));
  }

  edit(code:string){
    for (let i = 0; i < this.products.length; i++) {
      if(this.products[i].code === code){
        this.editProduct = new Product(this.products[i].name, this.products[i].code, this.products[i].available, this.products[i].price,this.products[i].rating);
      }
    }
  }

  update(){
    for (let i = 0; i < this.products.length; i++) {
      if(this.products[i].name == this.editProduct.name){
        this.products[i].code = this.editProduct.code;
        this.products[i].available = this.editProduct.available;
        this.products[i].price = this.editProduct.price;
        this.products[i].rating = this.editProduct.rating;
        break;
      }
    }
  }

  delete(code:string){
    for (let i = 0; i < this.products.length; i++) {
      if(this.products[i].code === code){
        this.products.splice(i,1);
        break;
      }
    }
  }

}

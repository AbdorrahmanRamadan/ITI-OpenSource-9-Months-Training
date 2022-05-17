import { Component } from "react";

export default class ImagesSlider extends Component{

    images = ["./1.jpg","./2.jpg","./3.jpg","./4.jpg"];
    i = 0;
    slideInterval = null;

    constructor(){
        super();
        this.state = {
            img:"./1.jpg",
        }
    }

    nextImg = ()=>{
        if(this.i<this.images.length-1){
            this.i++;
            this.setState({img:this.images[this.i]});
            clearInterval(this.slideInterval)
        }
    }

    prevImg = ()=>{
        if(this.i>0){
            this.i--;
            this.setState({img:this.images[this.i]})
            clearInterval(this.slideInterval)
        }
    }

    slide = ()=>{
        this.slideInterval = setInterval(this.doSlide, 1000);
    }

    doSlide = ()=>{
        if(this.i<this.images.length-1){
            this.i++;
            this.setState({img:this.images[this.i]});
        }else{
            this.i = 0;
            this.setState({img:this.images[this.i]});
        }
    }

    stopSlider = ()=>{
        clearInterval(this.slideInterval)
    }

    render(){
        return(
            <div style={{position:'absolute',top:'500px', left:'825px' }}>
                        <img src={this.state.img} alt="Slider"/><br/>
                        <input
                            type="button"
                            value="Previous"
                            onClick={this.prevImg}
                        />
                        <input
                            type="button"
                            value="Next"
                            onClick={this.nextImg}
                        />
                        <input
                            type="button"
                            value="Slide"
                            onClick={this.slide}
                        />
                        <input
                            type="button"
                            value="Stop"
                            onClick={this.stopSlider}
                        />
            </div>
        )
    }
}
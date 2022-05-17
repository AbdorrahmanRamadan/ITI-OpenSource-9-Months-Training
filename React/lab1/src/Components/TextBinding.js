import { Component } from "react";

export default class TextBinding extends Component{

    constructor(){
        super();
        this.state = {
            txt:"",
        }
    }

    resetText = ()=>{
        this.setState({txt:""})
    }

    render(){
        return(
            <div>
                    <input
                        type="text"
                        value={this.state.txt}
                        onChange={(e)=>{
                            this.setState({txt:e.target.value})
                        }}
                    />
                    <input
                        type="button"
                        value="Clear"
                        onClick={this.resetText}
                    />
                    <h4>{this.state.txt}</h4>
            </div>
        )
    }
}
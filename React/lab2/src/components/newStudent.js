import { Component } from "react";

class NewStudent extends Component {
  constructor(props) {
    super(props);
    this.state = {
      name: "",
      age: 0,
    };
  }

  sendData = () => {
    this.props.incomingData({ name: this.state.name, age: this.state.age });
  };

  render() {
    return (
        <div>
            <span>
              Name
            </span>
            <input
              type="text"
              value={this.state.txt}
              onChange={(e) => {
                this.setState({ name: e.target.value });
              }}
            />
            <span>
              Age
            </span>
            <input
              type="text"
              value={this.state.txt}
              onChange={(e) => {
                this.setState({ age: e.target.value });
              }}
            />
            <input
              type="button"
              value="Add"
              onClick={this.sendData}
            />
        </div>
    );
  }
}

export default NewStudent;

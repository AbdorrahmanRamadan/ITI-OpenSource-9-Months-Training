import { Component } from "react";
import AllStudents from "./students.json";
import NewStudent from "./newStudent";
import StudentsList from "./studentsList";

export default class Home extends Component {
  constructor() {
    super();
    this.state = {
      allStudents: AllStudents.students,
    };
  }

  receivedData = (text) => {
    let newList = this.state.allStudents.concat(text);
    this.setState({ allStudents: newList });
  };

  render() {
    return (
      <div>
        <NewStudent incomingData={this.receivedData} />
        <StudentsList students={this.state.allStudents} />
      </div>
    );
  }
}

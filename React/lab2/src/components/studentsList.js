import { NavLink } from "react-router-dom";

let studentsList = ({ students }) => {
  let renderStudents = () => {
    return students.map((student) => {
      let uri = "/student/".concat(student.name).concat('/').concat(student.age);
      return (
        <tr>
          <td>{student.name}</td>
          <td>{student.age}</td>
          <td>
            <NavLink to={uri} value="Details">
              Details
            </NavLink>
          </td>
        </tr>
      );
    });
  };

  return (
    <div>
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>Age</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>{renderStudents()}</tbody>
      </table>
    </div>
  );
};

export default studentsList;

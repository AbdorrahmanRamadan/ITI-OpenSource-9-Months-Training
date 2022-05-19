import { useParams } from "react-router-dom";

let UserDetails = () => {
  let { name } = useParams();
  let { age } = useParams();

  return (
    <div>
      <h3>Hello {name}</h3>
      <p>your age is {age}</p>
    </div>
  );
};

export default UserDetails;

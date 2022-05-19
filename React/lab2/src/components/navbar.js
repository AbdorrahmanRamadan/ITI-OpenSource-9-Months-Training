import { NavLink } from "react-router-dom";

let navbar = () => {
  return (
      <div>
        <NavLink to={"/"}>Lab 2</NavLink>
        <NavLink to={"/home"}>Home</NavLink>
        <NavLink to={"/about"}>About</NavLink>
        <NavLink to={"/dgfhghd"}>Error</NavLink>
      </div>
  );
};

export default navbar;

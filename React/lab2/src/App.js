import { BrowserRouter, Route, Routes } from "react-router-dom";
import Navbar from "./components/navbar";
import Home from "./components/home";
import About from "./components/about";
import Error from "./components/error";
import StudentDetails from "./components/UserDetails";

function App() {
  return (
      <BrowserRouter>
        <Navbar/>
        <Routes>
          <Route path="" element={<Home/>}/>
          <Route path="/home" element={<Home/>}/>
          <Route path="/about" element={<About/>} />
          <Route path="/student/:name/:age" element={<StudentDetails/>} />
          <Route path="*" element={<Error/>}/>
        </Routes>
      </BrowserRouter>
  );
}

export default App;

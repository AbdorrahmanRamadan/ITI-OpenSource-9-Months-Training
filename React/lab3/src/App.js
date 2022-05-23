import './App.css';
import {Routes, Route} from "react-router-dom";
import Home from "./pages/Home";
import Artists from "./pages/Artists";
import Artist from "./pages/Artist";

function App() {
  return (
    <div className="App">
      <Routes>
          <Route path="/" element={<Home/>} />
          <Route path="/artists" element={<Artists/>} />
          <Route path="/artists/:id" element={<Artist/>} />
      </Routes>
    </div>
  );
}

export default App;

import {Link} from "react-router-dom";

function Home() {
    return (
        <div className={'home'}>
            <Link to={'/artists'}>Music DB</Link>
        </div>
    );
}

export default Home;
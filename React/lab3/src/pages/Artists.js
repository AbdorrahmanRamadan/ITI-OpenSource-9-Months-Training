import {useState, useEffect} from "react";
import axios from "axios";
import ArtistCard from "../components/ArtistCard";

function Artists() {
    const [artists, setArtists] = useState([]);

    const getArtists = async () => {
        const response = await axios.get("http://localhost:3500/artists");
        return await response.data;
    }

    const renderArtists = () => {
        if(artists.length > 0) {
            return artists.map(artist => {
                return (<ArtistCard key={artist.id} artist={artist} />);
            });
        } else {
            return <h2>No artists found</h2>;
        }
    }

    useEffect(() => {
        getArtists().then(data => {
            setArtists(data);
        });
    }, []);

    return (
        <div className={'artists-container'}>
            {renderArtists()}
        </div>
    );
}

export default Artists;
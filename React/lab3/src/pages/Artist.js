import {Link, useParams} from "react-router-dom";
import {useState, useEffect} from "react";
import axios from "axios";
import AlbumGrid from "../components/AlbumGrid";

function Artist() {
    const [artist, setArtist] = useState(null);
    const {id} = useParams();

    const getArtist = async (id) => {
        const response = await axios.get(`http://localhost:3500/artists/${id}`);
        return await response.data;
    }

    useEffect(() => {
        getArtist(id).then(data => {
            setArtist(data);
        });
    }, [id]);

    if (!artist) {
        return <div>Loading...</div>
    }

    return (
        <div className={'artist-details'}>
            <Link to={'/artists'}>Music DB</Link>
            <hr/>
            <div className={'artist-details-info'}>
                <img src={`/images/covers/${artist.cover}.jpg`} alt={artist.name}/>
                <h1>{artist.name}</h1>
                <p>{artist.bio}</p>
                <AlbumGrid albums={artist.albums}/>
            </div>
        </div>
    );
}

export default Artist;
import {Link} from "react-router-dom";

function ArtistCard({artist}) {
    return (
        <div className={'artist-card'}>
            <img src={`/images/covers/${artist.cover}.jpg`} alt={artist.name}/>
            <Link to={`/artists/${artist.id}`}>
                <h2>{artist.name}</h2>
            </Link>
        </div>
    );
}

export default ArtistCard;
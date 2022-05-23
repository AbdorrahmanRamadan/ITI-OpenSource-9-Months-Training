function AlbumGrid({albums}) {
    return (
        <div className="album-covers-grid">
            {albums.map(album => (
                <img src={`/images/albums/${album.cover}.jpg`} alt={album.title} key={album.albumId}/>
            ))}
        </div>
    );
}

export default AlbumGrid;
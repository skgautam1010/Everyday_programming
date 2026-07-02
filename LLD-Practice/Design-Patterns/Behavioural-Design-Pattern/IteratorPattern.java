import java.util.ArrayList;
import java.util.List;

class Video {
    private String title;
    public Video(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

interface PlaylistIterator {
    boolean hasNext();
    Video next();
}

interface PlayList {
    PlaylistIterator createIterator();
}

class YoutubePlaylist implements PlayList{
    private List<Video> videoList = new ArrayList<>();
    
    public void addVideo(Video video) {
        videoList.add(video);
    }
    @Override
    public PlaylistIterator createIterator() {
        return new YoutubePlaylistIterator(videoList);
    }

    /*public List<Video> getVideos() {
        return videoList;
    }*/
    
}



class YoutubePlaylistIterator implements PlaylistIterator {
    private List<Video> videoList;
    private int position;

    public YoutubePlaylistIterator(List<Video> videos) {
        this.videoList = videos;
        this.position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < videoList.size();
    }

    @Override
    public Video next() {
       return hasNext() ? videoList.get(position++) : null;
    }
    
}




public class IteratorPattern {
    public static void main(String[] args) {
        YoutubePlaylist youtubePlaylist = new YoutubePlaylist();
        youtubePlaylist.addVideo(new Video("ABC"));
        youtubePlaylist.addVideo(new Video("XYZ"));
        /*for(Video v : youtubePlaylist.getVideos()) {
            System.out.println(v.getTitle());
        }*/
        //PlaylistIterator playlistIterator = new YoutubePlaylistIterator(youtubePlaylist.getVideos());
        PlaylistIterator playlistIterator = youtubePlaylist.createIterator();
        while(playlistIterator.hasNext()) {
            System.out.println(playlistIterator.next().getTitle());
        }
    }    
}

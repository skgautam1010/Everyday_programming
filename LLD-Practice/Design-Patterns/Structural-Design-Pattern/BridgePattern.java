interface VideoQuality {
    void load(String title);
}


class HDQuality implements VideoQuality {

    @Override
    public void load(String title) {
        System.out.println("Video loaded for: " + title + " in HD Quality");
    }
    
}


class UltraHD implements VideoQuality {

    @Override
    public void load(String title) {
        System.out.println("Video loaded for: " + title + " in Ultra HD Quality");
    }
}


abstract class VideoPlayer{
    protected  VideoQuality videoQuality;
    public VideoPlayer(VideoQuality videoQuality) {
        this.videoQuality = videoQuality;
    }

    public abstract void playVideo(String title);
}


class MobileVideoPlayer extends VideoPlayer {

    public MobileVideoPlayer(VideoQuality videoQuality) {
        super(videoQuality);
    }

    @Override
    public void playVideo(String title) {
        System.out.println("Video Streaming for: " + title);
        videoQuality.load(title);
    }
    
}

class TvVideoPlayer extends VideoPlayer {

    public TvVideoPlayer(VideoQuality videoQuality) {
        super(videoQuality);
    }

    @Override
    public void playVideo(String title) {
        System.out.println("Video Streaming for: " + title);
        videoQuality.load(title);
    }

}


public class BridgePattern {
    public static void main(String[] args) {
        VideoPlayer videoPlayer = new TvVideoPlayer(new HDQuality());
        videoPlayer.playVideo("testVideo");
        videoPlayer = new MobileVideoPlayer(new UltraHD());
        videoPlayer.playVideo("trialVideo");
    }
}

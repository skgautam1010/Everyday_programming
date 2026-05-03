import java.util.HashMap;
import java.util.Map;

interface VideoDownloader {
    String downloadVideo(String viedoUrl);
}


class RealVideoDownloader implements VideoDownloader {

    @Override
    public String downloadVideo(String viedoUrl) {
        System.out.println("Started to download the video for video url : " + viedoUrl);
        return "Video Downloaded Successfully : " + viedoUrl;
    }

}

class ProxyVideoDownloader implements VideoDownloader {

    private RealVideoDownloader realVideoDownloader;
    private Map<String, String> cachedVideo = new HashMap<>();

    

    @Override
    public String downloadVideo(String viedoUrl) {
        //Lazy Initialization
        if(cachedVideo.containsKey(viedoUrl)) {
            System.out.println("Cached Video Served: " + viedoUrl);
            return cachedVideo.get(viedoUrl);
        }
        if(realVideoDownloader == null) {
            realVideoDownloader = new RealVideoDownloader();
        }

        String video = realVideoDownloader.downloadVideo(viedoUrl);
        cachedVideo.put(viedoUrl, video);
        return video;
    }
    
}



public class ProxyPattern {
    public static void main(String[] args) {
        ProxyVideoDownloader proxyVideoDownloader = new ProxyVideoDownloader();
        proxyVideoDownloader.downloadVideo("https://www.testvideo.mp4");
        proxyVideoDownloader.downloadVideo("https://www.testvideo.mp4");
        ProxyVideoDownloader proxyVideoDownloader2 = new ProxyVideoDownloader();
        proxyVideoDownloader2.downloadVideo("https://www.testvideo.mp4");
    }
}

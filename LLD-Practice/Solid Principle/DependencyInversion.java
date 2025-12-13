interface RecommendationStrategy {
    void recommend();
    
}
class TrendingRecommendation implements RecommendationStrategy {
    public void recommend() {
        System.out.println("Trending");
    }
}
class GenreRecommendation implements RecommendationStrategy {
    public void recommend() {
        System.out.println("Genre");
    }
}
class RecentRecommendation implements RecommendationStrategy {
    public void recommend() {
        System.out.println("Recent");
    }
}

class RecommendationAlgorithm {
    private RecommendationStrategy recommendationStrategy;
    public RecommendationAlgorithm(RecommendationStrategy recommendationStrategy) {
        this.recommendationStrategy = recommendationStrategy;
    }
    public void recommendation() {
        recommendationStrategy.recommend();
    }
}

public class DependencyInversion {
    public static void main(String[] args) {
        //RecommendationAlgorithm recommendationAlgorithm = new RecommendationAlgorithm(new TrendingRecommendation());
        RecommendationAlgorithm recommendationAlgorithm = new RecommendationAlgorithm(new RecentRecommendation());
        recommendationAlgorithm.recommendation();        
    }    
}

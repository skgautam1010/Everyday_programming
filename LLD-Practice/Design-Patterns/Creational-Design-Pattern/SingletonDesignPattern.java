
//Eager Loading
/*class JudgeAnalytics {
    private static final JudgeAnalytics judgeAnalytics = new JudgeAnalytics();
    private JudgeAnalytics() {

    }

    public static JudgeAnalytics getJudgeAnalytics() {
        return judgeAnalytics;
    }
}*/

//Lazy Loading
/*class JudgeAnalytics {
    private static JudgeAnalytics judgeAnalytics;
    private JudgeAnalytics() {

    }

    public static JudgeAnalytics getJudgeAnalytics() {
        if(judgeAnalytics == null) {
            judgeAnalytics = new JudgeAnalytics();
        }
        return judgeAnalytics;
    }
}*/
//Synchronized
/*class JudgeAnalytics {
    private static JudgeAnalytics judgeAnalytics;
    private JudgeAnalytics() {

    }

    public static synchronized  JudgeAnalytics getJudgeAnalytics() {
        if(judgeAnalytics == null) {
            judgeAnalytics = new JudgeAnalytics();
        }
        return judgeAnalytics;
    }
}*/

//Double Check Locking

/*class JudgeAnalytics {
    private static volatile JudgeAnalytics judgeAnalytics;
    private JudgeAnalytics() {

    }

    public static JudgeAnalytics getJudgeAnalytics() {
        if(judgeAnalytics == null) {
            synchronized (JudgeAnalytics.class) {
                if(judgeAnalytics == null) {
                    judgeAnalytics = new JudgeAnalytics();
                }
            }
            
        }
        return judgeAnalytics;
    }
}*/


//Best Practice for Lazy Laoding
class JudgeAnalytics {
    private JudgeAnalytics() {
    }

    private static class Holder {
        private static final JudgeAnalytics judgeAnalytics = new JudgeAnalytics();
    }

    public static JudgeAnalytics getJudgeAnalytics() {
        return Holder.judgeAnalytics;
    }
}



public class SingletonDesignPattern {
    public static void main(String[] args) {
        JudgeAnalytics judgeAnalytics = JudgeAnalytics.getJudgeAnalytics();
        JudgeAnalytics judgeAnalytics2 = JudgeAnalytics.getJudgeAnalytics();
        System.out.println(judgeAnalytics);
        System.out.println(judgeAnalytics2); 
    }    
}

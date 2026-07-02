import java.util.Arrays;
import java.util.List;
import java.util.Stack;

class ResumeEditor {

    private String name;
    private String education;
    private String experience;
    private List<String> skills;
    
    public void setName(String name) {
        this.name = name;
    }
    public void setEducation(String education) {
        this.education = education;
    }

    public void setExperience(String experience) {
        this.experience = experience;
    }

    public void setSkills(List<String> skills) {
        this.skills = skills;
    }


    public void printResume() {
        System.out.println("x:----- Resume -----");
        System.out.println("Name: " + name);
        System.out.println("Education: " + education);
        System.out.println("Experience: " + experience);
        System.out.println("Skills: " + skills);
        System.out.println("x:------------------");
    }

    public ResumeMemento save() {
        return new ResumeMemento(name, education, experience, List.copyOf(skills));
    }

    public void restore(ResumeMemento memento) {
        this.name = memento.getName();
        this.education = memento.getEducation();
        this.experience = memento.getExperience();
        this.skills = memento.getSkills();
    }



    public static class ResumeMemento {
        private final String name;
        private final String education;
        private final String experience;
        private final List<String> skills;

        private ResumeMemento(String name, String education, String experience, List<String> skills) {
            this.name = name;
            this.education = education;
            this.experience = experience;
            this.skills = skills;
        }

        public String getName() {
            return name;
        }

        public String getEducation() {
            return education;
        }
        public String getExperience() {
            return experience;
        }
        public List<String> getSkills() {
            return skills;
        }

    }
}

class ResumeHistory {
    Stack<ResumeEditor.ResumeMemento> history = new Stack<>();

    public void save(ResumeEditor editor) {
        history.push(editor.save());
    }

    public void undo(ResumeEditor editor) {
        if(!history.isEmpty()) {
            editor.restore(history.pop());
        }
    }
}



public class MementoPattern {
    public static void main(String[] args) {
        ResumeEditor resumeEditor = new ResumeEditor();
        ResumeHistory resumeHistory = new ResumeHistory();

        resumeEditor.setName("Test");
        resumeEditor.setEducation("Test Education");
        resumeEditor.setExperience("Test Exp");
        resumeEditor.setSkills(Arrays.asList("Java", "C++"));

        resumeEditor.printResume();
        resumeHistory.save(resumeEditor);
        resumeEditor.setExperience("2 years");
        resumeEditor.setSkills(Arrays.asList("Java", "SpringBoot"));
        resumeHistory.save(resumeEditor);
        resumeEditor.printResume();
        resumeHistory.undo(resumeEditor);
        resumeEditor.printResume();
        
    }
}

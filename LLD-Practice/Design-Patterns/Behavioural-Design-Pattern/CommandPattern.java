import java.util.Stack;

class Light {
    public void on() {
        System.out.println("Light Turned On");
    }
    public void Off() {
        System.out.println("Light Turned Off");
    }
}

class AC {
    public void on() {
        System.out.println("AC On");
    }
    public void off() {
        System.out.println("AC Off");
    }
}

interface Command {
    void execute();
    void undo();
}

class AcOnCommand implements Command {

    private AC ac;
    public AcOnCommand(AC ac) {
        this.ac = ac;
    }

    @Override
    public void execute() {
     ac.on();   
    }

    @Override
    public void undo() {
        ac.off();
    }
    
}

class AcOffCommand implements Command {

    private AC ac;
    public AcOffCommand(AC ac) {
        this.ac = ac;
    }

    @Override
    public void execute() {
     ac.off();   
    }

    @Override
    public void undo() {
        ac.on();
    }
    
}

class LightOnCommand implements Command {
    private Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.on();
    }

    @Override
    public void undo() {
        light.Off();
    }
    
}

class LightOffCommand implements Command {
    private Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.Off();
    }

    @Override
    public void undo() {
        light.on();
    }
}

class NightModeCommand implements Command {
    
    private Command[] commands;

    public NightModeCommand(Command[] commands) {
        this.commands = commands;
    }

    @Override
    public void execute() {
        System.out.println("Night Mode Activated");
        for(Command command : commands) {
            command.execute();
        }
    }

    @Override
    public void undo() {
      for(int i=commands.length-1;i>=0;i--) {
        commands[i].undo();
      }
    }
    
}

class RemoteControl  {
    private Command[] buttons = new Command[5];
    private Stack<Command> commandHistory = new Stack<>();

    public void setCommand(int position, Command command) {
        buttons[position] = command;
    }

    public void pressButton(int position) {
        if(buttons[position] != null) {
            buttons[position].execute();
            commandHistory.push(buttons[position]);
        } else {
            System.out.println("No Command assigned to slot : " + position);
        }
    }

    public void pressUndo() {
        if(!commandHistory.isEmpty()) {
            commandHistory.pop().undo();
        } else {
            System.out.println("No commands to undo");
        }
    }
}


/*class NaiveRemoteControl {
    private final Light light;
    private final AC ac;
    private String last_action="";
    public NaiveRemoteControl(Light light, AC ac) {
        this.light = light;
        this.ac = ac;
    }

    public void turnLightOn() {
        light.on();
        last_action = "LIGHT_ON";
    }

    public void turnLightOff() {
        light.Off();
        last_action="LIGHT_OFF";
    }
    public void turnAcOn() {
        ac.on();
        last_action = "AC_ON";
    }
    public void turnAcOff() {
        ac.off();
        last_action = "AC_OFF";
    }
    public void undo() {
        switch(last_action) {
            case "LIGHT_ON" : light.Off(); last_action = "LIGHT_OFF"; break;
            case "LIGHT_OFF" : light.on(); last_action = "LIGHT_ON"; break;
            case "AC_ON" : ac.off(); last_action = "AC_OFF"; break;
            case "AC_OFF" : ac.on(); last_action = "AC_ON"; break;
            default: System.out.println("No action to undo"); break;
        }
    }

}*/




public class CommandPattern {
    public static void main(String[] args) {
        Light light = new Light();
        AC ac = new AC();
        /*NaiveRemoteControl remote = new NaiveRemoteControl(light, ac);

        remote.turnLightOn();
        remote.turnAcOn();
        remote.turnLightOff();
        remote.undo();
        remote.turnAcOff();
        remote.undo();*/

        RemoteControl remoteControl = new RemoteControl();
        remoteControl.setCommand(0, new LightOnCommand(light));
        remoteControl.setCommand(1, new LightOffCommand(light));
        remoteControl.setCommand(2, new AcOnCommand(ac));
        remoteControl.setCommand(3, new AcOffCommand(ac));
        remoteControl.setCommand(4, new NightModeCommand(new Command[]{new LightOffCommand(light), new AcOnCommand(ac)}));
        remoteControl.pressButton(2);
        remoteControl.pressButton(1);
        remoteControl.pressButton(3);
        remoteControl.pressButton(0);
        remoteControl.pressButton(2);
        remoteControl.pressButton(4);
        remoteControl.pressUndo();
        remoteControl.pressUndo();
        remoteControl.pressUndo();
    }
}

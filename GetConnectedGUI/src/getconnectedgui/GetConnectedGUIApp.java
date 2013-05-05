/*
 * GetConnectedGUIApp.java
 */

package getconnectedgui;

import java.io.FileNotFoundException;
import java.io.IOException;
import org.jdesktop.application.Application;
import org.jdesktop.application.SingleFrameApplication;

/** GetConnectedGUIApp Main class; receives Arduino input and stores the sounds. */
public class GetConnectedGUIApp extends SingleFrameApplication {
    /** Public Animal String array; stores all 4 different animal sounds */
    public String[] animalSound={"cow.wav","sheep.wav","pig.wav","chicken.wav"};
    /**
     * At startup create and show the main frame of the application.
     */
    @Override protected void startup() {
        show(new GetConnectedGUIView(this));
    }

    /**
     * This method is to initialize the specified window by injecting resources.
     * Windows shown in our application come fully initialized from the GUI
     * builder, so this additional configuration is not needed.
     */
    @Override protected void configureWindow(java.awt.Window root) {
    }

    /**
     * A convenient static getter for the application instance.
     * @return the instance of GetConnectedGUIApp
     */
    public static GetConnectedGUIApp getApplication() {
        return Application.getInstance(GetConnectedGUIApp.class);
    }
        /**@param SetDier receives animal type (int) from Arduino */
        public void setDier(String dier){
        
        JavaSound player = new JavaSound();
        if (dier.equals("1")){
            GetConnectedGUIView.animalLabel.setIcon(GetConnectedGUIView.iconKoe);
            player.playFile(animalSound[0]);
        }else if (dier.equals("4")){
            GetConnectedGUIView.animalLabel.setIcon(GetConnectedGUIView.iconSchaap);
            player.playFile(animalSound[1]);
        }else if (dier.equals("3")){
            GetConnectedGUIView.animalLabel.setIcon(GetConnectedGUIView.iconVarken);
            player.playFile(animalSound[2]);
        }else if (dier.equals("2")){
            GetConnectedGUIView.animalLabel.setIcon(GetConnectedGUIView.iconKip);
            player.playFile(animalSound[3]);
        }
    }

    /**
     * Main method launching the application.
     */
    public static void main(String[] args) {
        try {
            SerialTest main = new SerialTest();
            main.initialize();
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        launch(GetConnectedGUIApp.class, args);
        
    }
}

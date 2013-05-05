/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package getconnectedgui;
import java.net.URL;
import java.applet.*;
import java.applet.Applet;

/**
 *
 * @author Mick
 */
/** JavaSound class; Creates an audio clip player so all animal sounds may be played in the main class. */
public class JavaSound extends Applet {

/**Method Description PlayFile() - sets the file to animalSound array from main class
     @param file  animalSound[x]*/
    public void playFile(String file) {
        try {
            URL soundToPlay = getClass().getResource(file);
            AudioClip player = Applet.newAudioClip(soundToPlay);
            player.play();
        } catch (Exception e) {e.printStackTrace();}
    }
    /**
     * Initialization method that will be called after the applet is loaded
     * into the browser.
     */

}

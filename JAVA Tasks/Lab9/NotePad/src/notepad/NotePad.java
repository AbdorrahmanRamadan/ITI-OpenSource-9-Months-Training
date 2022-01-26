/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */

package notepad;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.fxml.*;
import javafx.scene.Parent;
/**
 *
 * @author AR
 */
public class NotePad extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Stage s = new Stage();
        Parent root = new FXMLBase(s);
        //FXMLLoader.load(getClass().getResource("FXML.fxml"));
        Scene scene = new Scene(root, 800, 750);

        s.setTitle("Untitled");
        s.setScene(scene);
        s.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}

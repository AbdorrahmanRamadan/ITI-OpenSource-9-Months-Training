/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */

package helloworld;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.scene.text.*;
import javafx.scene.effect.*;
import javafx.scene.paint.*;
/**
 *
 * @author AR
 */
public class HelloWorld extends Application {

    @Override
    public void start(Stage primaryStage) {
        Text text = new Text("Hello World");
        text.setEffect(new Reflection());
        StackPane stackPane = new StackPane();
        stackPane.setPrefHeight(400);
        stackPane.setPrefWidth(400);
        stackPane.getChildren().add(text);
        Scene scene = new Scene(stackPane);
        
        //using JAVAFX
       
        /*
        text.setFill(Color.RED);
        text.setFont(Font.font("Georgia",60));
        Stop[] stops = {new Stop(0, Color.BLACK), new Stop(0.5, Color.WHITE),new Stop(1, Color.BLACK)};
        LinearGradient lg = new LinearGradient(0, 0, 0, 1, true, CycleMethod.NO_CYCLE, stops);
        scene.setFill(lg);
        */

        //using CSS
        
        
        stackPane.setId("background");
        text.setId("text");
        scene.getStylesheets().add("Style.css");
        

        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}

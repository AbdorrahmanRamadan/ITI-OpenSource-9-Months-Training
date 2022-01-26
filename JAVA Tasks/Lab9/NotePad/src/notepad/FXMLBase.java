package notepad;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Optional;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextArea;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.layout.BorderPane;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCombination;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;

public class FXMLBase extends BorderPane{

    protected final MenuBar menuBar;
    protected final Menu fileMenu;
    protected final MenuItem newItem;
    protected final MenuItem openItem;
    protected final MenuItem saveItem;
    protected final MenuItem saveAsItem;
    protected final SeparatorMenuItem separatorMenuItem;
    protected final MenuItem exitItem;
    protected final Menu editMenu;
    protected final MenuItem copyItem;
    protected final MenuItem cutItem;
    protected final MenuItem pasteItem;
    protected final MenuItem selectAllItem;
    protected final MenuItem deleteItem;
    protected final Menu helpMenu;
    protected final MenuItem aboutItem;
    protected final TextArea textArea;
    String currentPath = null;      
    String noteName = null;
    boolean changed = false;

    public FXMLBase(Stage stage) {
        menuBar = new MenuBar();
        fileMenu = new Menu();
        newItem = new MenuItem();
        openItem = new MenuItem();
        saveItem = new MenuItem();
        saveAsItem = new MenuItem();
        separatorMenuItem = new SeparatorMenuItem();
        exitItem = new MenuItem();
        editMenu = new Menu();
        copyItem = new MenuItem();
        cutItem = new MenuItem();
        pasteItem = new MenuItem();
        selectAllItem = new MenuItem();
        deleteItem = new MenuItem();
        helpMenu = new Menu();
        aboutItem = new MenuItem();
        textArea = new TextArea();

        textArea.textProperty().addListener(e -> {changed = true;});

        
        setMaxHeight(USE_PREF_SIZE);
        setMaxWidth(USE_PREF_SIZE);
        setMinHeight(USE_PREF_SIZE);
        setMinWidth(USE_PREF_SIZE);
        setPrefHeight(400.0);
        setPrefWidth(600.0);

        BorderPane.setAlignment(menuBar, javafx.geometry.Pos.CENTER);

        fileMenu.setMnemonicParsing(false);
        fileMenu.setText("File");

        newItem.setMnemonicParsing(false);
        newItem.setText("New");
        newItem.setAccelerator(new KeyCodeCombination(KeyCode.N, KeyCombination.CONTROL_DOWN));
        newItem.setOnAction(e ->  {textArea.clear();});

        openItem.setMnemonicParsing(false);
        openItem.setText("Open");
        openItem.setAccelerator(new KeyCodeCombination(KeyCode.P, KeyCombination.CONTROL_DOWN));
        openItem.setOnAction(e ->  {
                FileChooser fileChooser = new FileChooser();
                fileChooser.setTitle("Select File");
                File selectedFile = fileChooser.showOpenDialog(stage);
                if (selectedFile != null) {
                    currentPath = selectedFile.getPath();
                    try {
                        FileInputStream fis = new FileInputStream(currentPath);
                        int size = fis.available();
                        byte[] text = new byte[size];
                        fis.read(text);
                        textArea.setText(new String(text));
                        changed = false;
                        noteName = selectedFile.getName();
                        stage.setTitle(noteName);
                        fis.close();
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        );

        saveItem.setMnemonicParsing(false);
        saveItem.setText("Save");
        saveItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN));
        saveItem.setOnAction(e ->  {
                if (currentPath == null) {
                    FileChooser fileChooser = new FileChooser();
                    fileChooser.setTitle("Save File");
                    File selectedFile = fileChooser.showSaveDialog(stage);
                    if (selectedFile != null) {
                        currentPath = selectedFile.getPath();
                        noteName = selectedFile.getName();
                        stage.setTitle(noteName);
                    }
                }
                if (currentPath != null) {
                    try {
                         FileOutputStream fos = new FileOutputStream(currentPath); 
                         byte[] text = textArea.getText().getBytes();
                         fos.write(text);
                         changed = false;
                         fos.close();
         
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        );
        saveAsItem.setMnemonicParsing(false);
        saveAsItem.setText("SaveAs");
        saveAsItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN, KeyCombination.SHIFT_DOWN));
        saveAsItem.setOnAction(e ->  {
                FileChooser fileChooser = new FileChooser();
                fileChooser.setTitle("Save File As");
                File selectedFile = fileChooser.showSaveDialog(stage);
                if (selectedFile != null) {
                    currentPath = selectedFile.getPath();
                    noteName = selectedFile.getName();
                    stage.setTitle(noteName);
                    try {
                        FileOutputStream fos = new FileOutputStream(currentPath);
                        byte[] text = textArea.getText().getBytes();
                        fos.write(text);
                        changed=false;
                        fos.close();
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }

        );

        separatorMenuItem.setMnemonicParsing(false);

        exitItem.setMnemonicParsing(false);
        exitItem.setText("Exit");
        exitItem.setAccelerator(new KeyCodeCombination(KeyCode.F4, KeyCombination.ALT_DOWN));
        exitItem.setOnAction(e ->  {
                if(changed){
                ButtonType save = new ButtonType("Save");
                ButtonType discard = new ButtonType("Discard");
                ButtonType cancel = new ButtonType("Cancel");
                String text = textArea.getText();
                Alert alert = new Alert(AlertType.WARNING, "Do you want to save changes ?", save, discard, cancel);
                Optional<ButtonType> result = alert.showAndWait();
                if (result.get() == save) {
                    if (currentPath == null) {
                        FileChooser fileChooser = new FileChooser();
                        fileChooser.setTitle("Save File");
                        File selectedFile = fileChooser.showSaveDialog(stage);
                        if (selectedFile != null) {
                            String path = selectedFile.getPath();
                            currentPath = path;
                        }
                    }
                    try {
                        if (currentPath != null) {
                            FileOutputStream fos = new FileOutputStream(currentPath);
                            byte[] textToWrite = textArea.getText().getBytes();
                            fos.write(textToWrite);
                            textArea.setText(new String(textToWrite));
                            fos.close();
                        }
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                } else {
                    if (result.get() == discard) {
                        stage.close();
                    }
                }
            }else{stage.close();}
        });

        editMenu.setMnemonicParsing(false);
        editMenu.setText("Edit");

        copyItem.setMnemonicParsing(false);
        copyItem.setText("Copy");
        copyItem.setAccelerator(new KeyCodeCombination(KeyCode.C, KeyCombination.CONTROL_DOWN));
        copyItem.setOnAction(e -> {textArea.copy();});

        cutItem.setMnemonicParsing(false);
        cutItem.setText("Cut");
        cutItem.setAccelerator(new KeyCodeCombination(KeyCode.X, KeyCombination.CONTROL_DOWN));
        cutItem.setOnAction(e -> {textArea.cut();});

        pasteItem.setMnemonicParsing(false);
        pasteItem.setText("Paste");
        pasteItem.setAccelerator(new KeyCodeCombination(KeyCode.V, KeyCombination.CONTROL_DOWN));
        pasteItem.setOnAction(e -> {textArea.paste();});

        selectAllItem.setMnemonicParsing(false);
        selectAllItem.setText("SelectAll");
        selectAllItem.setAccelerator(new KeyCodeCombination(KeyCode.A, KeyCombination.CONTROL_DOWN));
        selectAllItem.setOnAction(e -> {textArea.selectAll();});

        deleteItem.setMnemonicParsing(false);
        deleteItem.setText("Delete");
        deleteItem.setAccelerator(new KeyCodeCombination(KeyCode.D, KeyCombination.CONTROL_DOWN));
        deleteItem.setOnAction(e -> {textArea.deleteText(textArea.getSelection());});
        helpMenu.setMnemonicParsing(false);
        helpMenu.setText("Help");

        aboutItem.setMnemonicParsing(false);
        aboutItem.setText("About");
        aboutItem.setAccelerator(new KeyCodeCombination(KeyCode.F10));
        aboutItem.setOnAction(e ->{
                Alert alert = new Alert(AlertType.INFORMATION, "this is some info about Notepad");
                alert.show();
            }
        );
        setTop(menuBar);

        BorderPane.setAlignment(textArea, javafx.geometry.Pos.CENTER);
        textArea.setPrefHeight(200.0);
        textArea.setPrefWidth(200.0);
        setCenter(textArea);

        fileMenu.getItems().add(newItem);
        fileMenu.getItems().add(openItem);
        fileMenu.getItems().add(saveItem);
        fileMenu.getItems().add(saveAsItem);
        fileMenu.getItems().add(separatorMenuItem);
        fileMenu.getItems().add(exitItem);
        menuBar.getMenus().add(fileMenu);
        editMenu.getItems().add(copyItem);
        editMenu.getItems().add(cutItem);
        editMenu.getItems().add(pasteItem);
        editMenu.getItems().add(selectAllItem);
        editMenu.getItems().add(deleteItem);
        menuBar.getMenus().add(editMenu);
        helpMenu.getItems().add(aboutItem);
        menuBar.getMenus().add(helpMenu);

    }
}

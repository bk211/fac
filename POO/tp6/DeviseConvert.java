import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.*;
import javafx.scene.Group;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.ComboBox;
import javafx.geometry.Insets;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class DeviseConvert extends Application{
    private Button ok =new Button("OK");
    private Button reset =new Button("Reset");
    private Button close = new Button("Close");
    private TextField source   =new TextField();
    private TextField dest=new TextField();
    // Taux de  change  des  differentes  monaies 
    //Toujours  dans  le meme ordre  :Vers  l ’ euro, l e  dollar, la  livre, 
    // le  Yuan et  le  Dinar .
    private static final double txChangeEuro [] ={1.0, 1.09189, 0.769736, 7.17154, 117.020};
    private static final double txChangeUSD[] ={0.917251 , 1.0, 0.705877, 6.57866, 107.353};
    private static final double txChangeLivreBrit  [] ={1.22915 , 1.41668, 1.0, 9.31846, 152.078};
    private static final double txChangeYuan[] ={0.139440 , 0.152007, 0.107314, 1.0, 16.3229};
    private static final double txChangeDinarAlg   [] ={0.00854555 , 0.00931510, 0.00657555, 0.0612635, 1.0};
    private static final double txChange [][]  ={txChangeEuro, txChangeUSD, txChangeLivreBrit, txChangeYuan, txChangeDinarAlg};

    @Override
    public void start(Stage  primaryStage){
        GridPane grid =new GridPane();
        grid.setVgap(4);
        grid.setHgap(10);
        grid.setPadding(new  Insets(5, 5, 5, 5));
        ComboBox monaieSource =new ComboBox();
        monaieSource.getItems().addAll("Euro","US Dolllar","Livrebritanique","Yuan","DinarAlgerien");
        ComboBox monaieDest =new ComboBox();
        monaieDest.getItems().addAll("Euro","USD olllar","Livrebritanique","Yuan","DinarAlgerien");
        grid.add(source, 0, 0);
        grid.add(monaieSource, 1, 0);
        grid.add(dest, 0, 1);
        grid.add(monaieDest, 1, 1);
        GridPane grid2 = new GridPane();
        grid2.setPadding(new Insets(5, 5, 5, 5));
        grid2.setHgap(10);
        grid2.add(reset, 0, 0);
        grid2.add(close, 1, 0);
        grid.add (grid2, 1,2);
        Scene scene =new Scene(grid, 400, 120);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String [] args){
        launch(args);
    }
    
}
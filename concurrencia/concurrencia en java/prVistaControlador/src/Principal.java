import javax.swing.*;

public class Principal {

    public static void main (String[] args) {
        // TODO Auto-generated method stub
        JFrame ventana = new JFrame("Ejemplo Scroll");
        Panel panel = new Panel();
        Controlador ctr = new Controlador(panel);
        panel.setControlador(ctr);
        ventana.setContentPane(panel);
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ventana.pack();
        ventana.setVisible(true);
    }

}

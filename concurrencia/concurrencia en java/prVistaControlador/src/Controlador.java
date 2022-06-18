import java.awt.event.*;

public class Controlador implements ActionListener {

    Panel p;

    public Controlador(Panel p) {
        this.p = p;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("COMENZAR")) {
            workerMontecarlo wm = new workerMontecarlo(p.getIteraciones(), p);
            workerSeries ws = new workerSeries(p.getIteraciones(), p);
            wm.execute();
            ws.execute();
        }
    }
}

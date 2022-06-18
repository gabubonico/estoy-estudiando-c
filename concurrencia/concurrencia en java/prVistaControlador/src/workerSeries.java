import javax.swing.*;
import java.util.concurrent.ExecutionException;

public class workerSeries extends SwingWorker<Float, Void> {

    private Panel p;
    private int numIter;

    public workerSeries(int n, Panel p) {
        this.p = p;
        numIter = n;
    }

    @Override
    protected Float doInBackground() throws Exception {
        float resul = 0.0F;

        for (int i = 1; i <= numIter; i += 4) {
            resul += 8.0 / (i * (i + 2F));
            p.escribePI2(Double.valueOf(resul));
            p.setProgresoLeibniz(i * 100 / numIter + 1);
        }

        return resul;
    }

    @Override
    protected void done() {
        try {
            p.escribePI2(Double.valueOf(get()));
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }
    }
}

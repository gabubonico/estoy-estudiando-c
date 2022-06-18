import javax.swing.*;
import java.util.Random;
import java.util.concurrent.ExecutionException;

public class workerMontecarlo extends SwingWorker<Float, Void> {

    private int numIter;
    private Panel p;

    public workerMontecarlo(int n, Panel p) {
        numIter = n;
        this.p = p;
    }

    @Override
    protected Float doInBackground() throws Exception {
        float numCirculo = 0.0F;
        float tamCirculo = 5.0F;
        Random r = new Random();

        for (int i = 1; i <= numIter; i++) {
            float x = r.nextFloat(5.0F);
            float y = r.nextFloat(5.0F);
            if ((x * x + y * y) < (tamCirculo * tamCirculo))
                numCirculo++;
            p.escribePI1(Double.valueOf((4 * numCirculo) / numIter));
            p.setProgresoMonteCarlo(i * 100 / numIter);
        }

        return (4 * numCirculo) / numIter;
    }

    @Override
    protected void done() {
        try {
            p.escribePI1(Double.valueOf(get()));
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }
    }
}

package impresoras;

import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.Semaphore;

public class SalaImpresorasS implements SalaImpresoras {
    private List<Integer> impresorasLibres;
    private Semaphore mutEx = new Semaphore(1,true);
    private boolean hayImpresora = true;

    public SalaImpresorasS(int n) {
        impresorasLibres = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            impresorasLibres.add(i);
        }
    }

    @Override
    public int quieroImpresora(int id) throws InterruptedException {
        System.out.println("El cliente "+id+" quiere impresoras");
        int i;
        if (hayImpresora) {
            mutEx.acquire();
            i = impresorasLibres.get(0);
            System.out.println("El cliente "+id+" coge la impresora "+i+". Quedan "+ (impresorasLibres.size() - 1));
            impresorasLibres.remove(0);
            mutEx.release();
            if (impresorasLibres.size() == 0) hayImpresora = false;
            return i;
        } else {
            wait();
        }
        return 0;
    }

    @Override
    public void devuelvoImpresora(int id, int n) throws InterruptedException {
        mutEx.acquire();
        impresorasLibres.add(n);
        System.out.println("El cliente "+id+" devuelve la impresora "+n+". Quedan "+ impresorasLibres.size());
        if (impresorasLibres.size() == 1) hayImpresora = true;
        mutEx.release();
    }
}

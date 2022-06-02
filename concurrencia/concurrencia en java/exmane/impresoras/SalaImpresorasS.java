package impresoras;

import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.Semaphore;

public class SalaImpresorasS implements SalaImpresoras {

    private int numImpresoras;
    private List<Integer> impresorasLibres;
    private Semaphore mutEx = new Semaphore(1,true);
    private Semaphore esperaImpresora = new Semaphore(1,true);


    public SalaImpresorasS(int n) {
        numImpresoras = n;
        impresorasLibres = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            impresorasLibres.add(i);
        }
    }

    @Override
    public int quieroImpresora(int id) throws InterruptedException {
        System.out.println("Cliente " + id + " quiere impresora ");
        esperaImpresora.acquire();
        mutEx.acquire();
        int resul = impresorasLibres.get(0);

        System.out.println("Cliente " + id + " coge impresora " + resul + " quedan libres " + impresorasLibres.size());

        if (impresorasLibres.size() > 0) {
            mutEx.release();
            esperaImpresora.release();
        } else {
            mutEx.release();
        }
        return resul;
    }

    @Override
    public void devuelvoImpresora(int id, int n) throws InterruptedException {
        mutEx.acquire();
        impresorasLibres.add(n);

        System.out.println("Cliente " + id + " devuelve la impresora " + n + " quedan libres " + impresorasLibres.size());

        if (impresorasLibres.size() == 1) {
            esperaImpresora.release();
        }
        mutEx.release();
    }
}

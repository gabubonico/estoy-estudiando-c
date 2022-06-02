package impresoras;

import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SalaImpresorasML implements SalaImpresoras {

    private boolean hayImpresora;
    private List<Integer> impresorasLibres;
    private Lock l = new ReentrantLock(true);
    private Condition espera = l.newCondition();

    public SalaImpresorasML(int n) {
        hayImpresora = true;
        impresorasLibres = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            impresorasLibres.add(i);
        }
    }

    @Override
    public int quieroImpresora(int id) throws InterruptedException {
        l.lock();
        int resul;
        try {
            System.out.println("El cliente "+id+" quiere impresora");
            while (!hayImpresora) espera.await();
            resul = impresorasLibres.get(0);
            System.out.println("    El cliente "+id+" coge impresora "+resul+" Quedan: "+(impresorasLibres.size()-1));
            impresorasLibres.remove(0);
            if (impresorasLibres.size() == 0) hayImpresora = false;
        } finally {
            l.unlock();
        }
        return resul;
    }

    @Override
    public void devuelvoImpresora(int id, int n) throws InterruptedException {
        l.lock();
        try {
            impresorasLibres.add(n);
            System.out.println("      El cliente "+id+" devuelve impresora "+n+" Quedan: "+impresorasLibres.size());
            hayImpresora = true;
            espera.signal();
        } finally {
            l.unlock();
        }
    }
}

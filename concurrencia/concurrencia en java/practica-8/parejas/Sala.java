package parejas;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Sala {
    private Lock l = new ReentrantLock(true);
    private Boolean hayHombre=false;
    private Boolean hayMujer = false;
    private Boolean cita=false;
    private Boolean puerta=true;

    private Condition okCitaH = l.newCondition();
    private Condition okCitaM = l.newCondition();

	/**
	 * un hombre llega a la sala para formar una pareja si ya hay otra mujer en la
	 * sala o si a�n no hay un hombre
	 * 
	 * @throws InterruptedException
	 */
	public synchronized void llegaHombre(int id) throws InterruptedException {
        try {
            l.lock();
            while(hayHombre || !puerta) okCitaH.await();
            // podemos pasar a la sala de espera
            hayHombre=true;
            System.out.println("El hombre "+id+" espera en la sala.");
            // ya hay una mujer esperando
            if(hayMujer) {
                puerta=false;
                cita=true;
                System.out.println("El hombre "+id+" ha tenido una cita.");
                okCitaM.signalAll();// desbloqueamos a la mujer.
            }else {// no hay mujer esperando.
                System.out.println("El hombre "+id+" espera pacientemente.");
                while(cita) okCitaH.await();
                System.out.println("El hombre "+id+" ha tenido una cita.");
                cita=false;
            }

            hayHombre=false;
            System.out.println("El hombre "+id+" sale de la sala.");
            if(!hayHombre && !hayMujer) {
                puerta=true;
                okCitaH.signalAll();
            }
        } finally {
            l.unlock();
        }
	}

	/**
	 * una mujer llega a la sala para formar una pareja debe esperar si ya hay otra
	 * mujer en la sala o si aún no hay un hombre
	 * 
	 * @throws InterruptedException
	 */
	public synchronized void llegaMujer(int id) throws InterruptedException {
        try {
            l.lock();
            while(hayMujer || !puerta) okCitaM.await();
            hayMujer=true;
            System.out.println("La mujer "+id+" espera en la sala.");
            if(hayHombre) {
                puerta=false;
                cita=true;
                System.out.println("La mujer  "+id+" ha tenido una cita.");
                okCitaH.signalAll();//desbloqueamos al hombre.
            }else {// no hay mujer esperando.
                System.out.println("La mujer "+id+" espera pacientemente.");
                while(cita) okCitaM.await();
                System.out.println("La mujer  "+id+" ha tenido una cita.");
                cita=false;
            }
            hayMujer=false;
            System.out.println("La mujer "+id+" sale de la sala.");
            if(!hayMujer && !hayHombre) {
                puerta=true;
                okCitaM.signalAll();
            }
        } finally {
            l.unlock();
        }
	}
}

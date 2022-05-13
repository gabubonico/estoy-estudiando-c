package sensores;

import java.util.concurrent.Semaphore;

public class Mediciones {
    private int num = 0;
    private static Semaphore scNum = new Semaphore(1,true);
    private static Semaphore esperaT = new Semaphore(0,true);
    private static Semaphore[] esperaS = new Semaphore[3];


    public Mediciones() {
        for (int i = 0; i < esperaS.length; i++) {
            esperaS[i] = new Semaphore(0,true);
        }
    }

    /**
     * El sensor id deja su medición y espera hasta que el trabajador
     * ha terminado sus tareas
     * 
     * @param id
     * @throws InterruptedException
     */
    public void nuevaMedicion(int id) throws InterruptedException {
        scNum.acquire();
        num++;
        System.out.println("Sensor " + id + " deja sus mediciones.");
        if (num == 3) {
            esperaT.release();
        }
        scNum.release();
        esperaS[id].acquire();
    }

    /***
     * El trabajador espera hasta que están las tres mediciones
     * 
     * @throws InterruptedException
     */
    public void leerMediciones() throws InterruptedException {
        esperaT.acquire();
        System.out.println("El trabajador tiene sus mediciones...y empieza sus tareas");

    }

    /**
     * El trabajador indica que ha terminado sus tareas
     */
    public void finTareas() throws InterruptedException {
        System.out.println("El trabajador ha terminado sus tareas");
        scNum.acquire();
        num = 0;
        for (int i = 0; i < esperaS.length; i++) {
            esperaS[i].release();
        }
        scNum.release();
    }

}

package fumadores;

import java.util.concurrent.*;

public class Mesa {

	// esta es una implementación pasiva para los fumadores
	// los van a despertar cuando tengan que fumar.

    private Semaphore[] fumador = new Semaphore[3];
    private Semaphore agente = new Semaphore();

	public Mesa() {
        for (int i = 0; i < fumador.length; i++) {
            fumador[i] = new Semaphore(1,true);
        }
	}

    /*
	public void qFumar(int id) {
        fumador[id].acquire;
		System.out.println("Fumador " + id + " coge los ingredientes");

	}
    */

	public void finFumar(int id) {
		System.out.println("Fumador " + id + " ha terminado de fumar");
        agente.release();
	}

    /*
	public void nuevosIng(int ing) { // se pasa el ingrediente que no se pone
        agente.acquire();
		System.out.print("El agente ha puesto los ingredientes ");
        if(ing == 0){

        } else if () {

        } else {

        }
    }
     */

}

// CS-Fumador i: No puede fumar hasta que el fumador anterior no ha terminado
// de fumar y sus ingredientes están sobre la mesa
// CS-Agente: no puede poner nuevos ingredientes hasta que el fumador anterior
// no ha terminado de fumar

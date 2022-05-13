package pajaritos;

import java.util.concurrent.*;

public class Nido {
	private int B = 10; // Número máximo de bichos
	private int bichitos; // puede tener de 0 a B bichitos

	private Semaphore padres = new Semaphore(1,true);
	private Semaphore hijos = new Semaphore(0,true);

	public void come(int id) throws InterruptedException {
		hijos.release();
		if (bichitos <= 0) {
			hijos.acquire();
		}
		bichitos--;
		System.out.println("El bebé " + id + " ha comido un bichito. Quedan " + bichitos);
		hijos.acquire();
	}

	public void nuevoBichito(int id) throws InterruptedException {
		// el papa/mama id deja un nuevo bichito en el nido
		padres.release();
		if (bichitos >= B) {
			padres.acquire();
		}
		bichitos++;
		System.out.println("El papá " + id + " ha añadido un bichito. Hay " + bichitos);
		padres.acquire();
	}
}

// CS-Bebe-i: No puede comer del nido si está vacío
// CS-Papa/Mama: No puede poner un bichito en el nido si está lleno

package aseos;

import java.util.concurrent.Semaphore;

public class Aseos {

	boolean limpiadores = false;
	int clientes = 0;
	private Semaphore sClientes = new Semaphore(1,true);
	private Semaphore sLimpiadores = new Semaphore(1,true);

	/**
	 * Utilizado por el cliente id cuando quiere entrar en los aseos
	 * CS Version injusta: El cliente espera si el equipo de limpieza está
	 * trabajando
	 * CS Version justa: El cliente espera si el equipo de limpieza está trabajando
	 * o
	 * está esperando para poder limpiar los aseos
	 * 
	 * @throws InterruptedException
	 * 
	 */
	public void entroAseo(int id) throws InterruptedException {
		sClientes.acquire();
		if (!limpiadores) {
			clientes++;
			System.out.println("El cliente " + id + " ha entrado en el baño."
					+ "Clientes en el aseo: " + clientes);
		}
		sClientes.release();
	}

	/**
	 * Utilizado por el cliente id cuando sale de los aseos
	 * 
	 * @throws InterruptedException
	 * 
	 */
	public void salgoAseo(int id) throws InterruptedException {
		sClientes.acquire();
		if (clientes > 0) {
			clientes--;
			System.out.println("El cliente " + id + " ha salido del baño."
					+ " Clientes en el aseo: " + clientes);
		}
		sClientes.release();
	}

	/**
	 * Utilizado por el Equipo de Limpieza cuando quiere entrar en los aseos
	 * CS: El equipo de trabajo está solo en los aseos, es decir, espera hasta que
	 * no
	 * haya ningún cliente.
	 * 
	 * @throws InterruptedException
	 * 
	 */
	public void entraEquipoLimpieza() throws InterruptedException {
		sLimpiadores.acquire();
		limpiadores = true;
		System.out.println("El equipo de limpieza está trabajando.");
		sLimpiadores.release();
	}

	/**
	 * Utilizado por el Equipo de Limpieza cuando sale de los aseos
	 * 
	 * @throws InterruptedException
	 * 
	 * 
	 */
	public void saleEquipoLimpieza() throws InterruptedException {
		sLimpiadores.acquire();
		limpiadores = false;
		System.out.println("El equipo de limpieza ha terminado.");
		sLimpiadores.release();
	}
}

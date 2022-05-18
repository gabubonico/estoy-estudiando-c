package electoresescritoresjustolocks;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class GestorBD {

	private int nLectores = 0;
	private boolean hayEscritor = false;
	private int nEscritores = 0;

	private Lock l = new ReentrantLock();

	private Condition okLeer = l.newCondition();
	private Condition okEscribir = l.newCondition();

	public synchronized void entraLector(int id) throws InterruptedException {

		while (hayEscritor || nEscritores > 0)
			wait();

		nLectores++;
		System.out.println("Entra lector " + id + ", hay " + nLectores + " lectores");

	}

	public synchronized void saleLector(int id) throws InterruptedException {
		l.lock();

		try {
			nLectores--;
			System.out.println("noseque");
			if (nLectores == 0) okEscribir.signal();
		} finally {
			l.unlock();
		}

		nLectores--;

		System.out.println("Sale lector " + id + ", hay " + nLectores + " lectores");

		if (nLectores == 0)
			notifyAll();

	}

	public synchronized void entraEscritor(int id) throws InterruptedException {

		nEscritores++;
		while (nLectores > 0 || hayEscritor) {
			wait();
		}

		hayEscritor = true;

		System.out.println("                    Entra escritor " + id);
	}

	public synchronized void saleEscritor(int id) throws InterruptedException {
		l.lock();
		try {
			hayEscritor = false;
			System.out.println("                    Sale escritor " + id);
			nEscritores--;
			notifyAll();
			if (nEscritores > 0) okEscribir.signal();
			//else??
		} finally {
			l.unlock();
		}
	}

}
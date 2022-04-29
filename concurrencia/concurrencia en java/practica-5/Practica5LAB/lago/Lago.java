package lago;

public class Lago {
	private volatile int nivel = 0;
	private volatile boolean hayDato = false;

	public Lago(int valorInicial) {
		nivel = valorInicial;
	}

	// f0IncDec, f0Inc
	public void incRio0() {
		while (hayDato) {
			Thread.yield();
		}
		nivel++;
		hayDato = true;
	}

	// f0IncDec, f1Inc
	public void incRio1() {
		while (hayDato) {
			Thread.yield();
		}
		nivel++;
		hayDato = true;
	}

	// f1IncDec, f0Dec
	public void decPresa0() {
		while (!hayDato) {
			Thread.yield();
		}
		nivel--;
		hayDato = false;
	}

	// f1IncDec, f1Dec
	public void decPresa1() {
		while (!hayDato) {
			Thread.yield();
		}
		nivel--;
		hayDato = false;
	}

	public int nivel() {
		return nivel;
	}
}

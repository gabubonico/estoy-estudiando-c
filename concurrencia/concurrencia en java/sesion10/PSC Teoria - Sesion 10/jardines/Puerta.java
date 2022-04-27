package jardines;

public class Puerta implements Runnable {
    Contador cont;
    int numVisitantes;

    public Puerta(Contador c, int numV) {
        cont = c;
        numVisitantes = numV;

    }

    @Override
    public void run() {
        for (int i = 0; i < numVisitantes; i++) {
            cont.inc();
        }

    }

}

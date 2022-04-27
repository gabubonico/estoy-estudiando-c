package jardines;

//Solventa el problema del jardín con semáforos.
//Tu solución debe funcionar para cualquier número de puertas N>1
public class Jardin {
    public static void main(String[] args) throws InterruptedException {
        Contador visitantes = new Contador();
        Thread puerta1 = new Thread(new Puerta(visitantes, 1000));
        Thread puerta2 = new Thread(new Puerta(visitantes, 1000));
        puerta1.start();
        puerta2.start();

        puerta1.join();
        puerta2.join();

        System.out.println("Hay " + visitantes.valor() + " visitantes");
    }
}
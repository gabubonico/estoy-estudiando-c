package acita;

/*
Primero resolver con semáforos.
Segundo resolver con wait and notify o notifyAll.
*/

public class Intercambio {
    private int v1, v2;

    // Acepta el dato generado por w1 y devuelve el de w2, OJO hasta que w2 no ha
    // dejado
    // dato, no se puede devolver
    public int Intercambio1(int dato) {
        v1 = dato;
        return v2;
    }

    // Acepta el dato generado por w2 y devuelve el de w1, OJO hasta que w1 no ha
    // dejado
    // dato, no se puede devolver
    public int Intercambio2(int dato) {
        v2 = dato;
        return v1;
    }
}
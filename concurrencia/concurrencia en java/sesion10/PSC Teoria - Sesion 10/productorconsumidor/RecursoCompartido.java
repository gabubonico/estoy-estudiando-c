package productorconsumidor;

//Condición Productor:
//  No puedo almacenar hasta que no se ha leido.  Un semáforo haySitio se puede encargar de sincronizar cuando hay hueco para almacenar.
//Condición Consumidor:
// No puedo extraer hasta que no se ha almacenado uno nuevo. Un semáforo hayDato se puede encargar de sincronizar cuando hay dato.

public class RecursoCompartido {
    private int recurso;

    public RecursoCompartido() {

    }

    public int extraer() {
        int datoLeido;

        datoLeido = recurso;
        System.out.println("Extraído " + datoLeido);

        return datoLeido;
    }

    public void almacenar(int r) {
        recurso = r;
        System.out.println("Almacenado " + r);
    }

}

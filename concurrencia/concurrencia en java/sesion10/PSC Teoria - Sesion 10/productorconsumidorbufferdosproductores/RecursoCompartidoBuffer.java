package productorconsumidorbufferdosproductores;

import java.util.Arrays;
import java.util.concurrent.Semaphore;

//Condiciones Productor:
//  No puedo almacenar mientras el buffer no tenga sitio.  Un semáforo haySitio se puede encargar de sincronizar cuando hay hueco para almacenar.
// Debo asegurar la exlusión mútua al escribir en el buffer ya que somos dos productores...con un semáforo binario exclusionMutua se puede conseguir.
// Condición Consumidor:
// No puedo extraer hasta que no hay datos. Un semáforo hayDato se puede encargar de sincronizar cuando hay dato.
//Se necesita un índice indInsertar para conocer dónde se intertará el siguiente elemento.
//Se necesita un índice indExtraer para conocer dónde se extraerá el siguiente elemento.
//Además, el buffer va a ser tratado de forma circular, una variable tam almacenará el tamaño del buffer para actualizar correctamente los índices.

public class RecursoCompartidoBuffer {
    private int[] recurso;
    Semaphore haySitio;
    Semaphore hayDato;
    Semaphore exclusionMutua;
    int indInsertar;
    int indExtraer;
    int tam;

    public RecursoCompartidoBuffer(int tam) {
        indInsertar = 0;
        indExtraer = 0;
        // ...
        recurso = new int[tam];
        this.tam = tam;

    }

    public int extraer() {
        int datoLeido;

        datoLeido = recurso[indExtraer];
        System.out.println("Extraído " + datoLeido);
        System.out.println(Arrays.toString(recurso));

        return datoLeido;
    }

    public void almacenar(int r) {

        System.out.println("Almacenado " + r);
        System.out.println(Arrays.toString(recurso));

    }

}

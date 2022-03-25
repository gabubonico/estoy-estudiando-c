
//https://docs.oracle.com/javase/8/docs/api/java/lang/Process.html
import java.io.File;
import java.io.IOException;

//programa para ejecutar el descifrar que no lo tengo hecho dxxdxd

public class ProcesosDinamicos {

    private static Process start;

    public static void main(String[] args) throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("descifrar", "./imagen/imagen2Encriptadaa.png",
                "./imagen/imagen2.png");

		pb.redirectError(new File("SalidaError.txt"));
		pb.redirectOutput(new File("SalidaNormal.txt"));

		Process p = pb.start();
		p.waitFor();
		System.out.print("Salida " + p.exitValue());
    }
}

import java.util.List;

public class Nodo extends Thread {
    
    private List<Integer> Lista;

    public Nodo (List<Integer> l) {
        Lista = l;
    }

    
    private void aniade (List<Integer> l, int desde, int hasta) {
        for (int i = desde; i < hasta; i++){
            Lista.set(i, l.get(i));
        }
    }
    

    private void mezcla (List<Integer> l1, List<Integer> l2) {
        // TODO
    }

    @Override
    
    public void run () {        
        if (Lista.size() < 2) {
            return;
        }

        int mid = Lista.size() / 2;
        List<Integer> izq = Lista.subList(0, mid);
        List<Integer> der = Lista.subList(mid, Lista.size() - 1); 

        Nodo ni = new Nodo(izq);
        Nodo nd = new Nodo(der);

        mezcla(ni.Lista, nd.Lista);
    }
    
    /*
    public void run() {
        if(Lista.size()) {
            List<Integer> TUPO UTA MADRE
        }
    }
    */
}

public class MiSegundaHebra extends Thread{
    Character myChar;

    public MiSegundaHebra (Character myChar){
        this.myChar = myChar;
    }

    @Override
    public void run(){
        for(int i = 0; i < 20; i++){
            System.out.print(myChar);
        }
    }
}

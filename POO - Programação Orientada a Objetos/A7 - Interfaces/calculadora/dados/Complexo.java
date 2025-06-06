package dados;

import java.util.Random;

public class Complexo {
  private int real;
  private int imaginaria;
 
  public Complexo(int real, int imaginaria){
    this.real = real;
    this.imaginaria = imaginaria;
  }

  public Complexo(){
    Random r = new Random();
    real = r.nextInt(100);
    imaginaria = r.nextInt(100);
  }

  public int getReal() {
    return real;
  }
  public int getImaginaria() {
    return imaginaria;
  }
  
  @Override
  public String toString() {
    return "[ " + real + " + " + imaginaria + "i]";
  }
}

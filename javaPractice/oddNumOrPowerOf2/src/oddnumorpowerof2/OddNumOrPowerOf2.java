/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oddnumorpowerof2;
import java.util.Scanner;
/**
 *
 * @author fury
 */
public class OddNumOrPowerOf2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter an integer\n>>");
        int input = 0;
        while(input!=-1){
            input = kb.nextInt();
            if(isOdd(input))
                System.out.println(input + " is odd");
            else
                System.out.println(input + " is even");
            if(isPowerOfTwo(input))
                System.out.println(input + " is a power of two");
            else
                System.out.println(input + " is not a power of two");
        }
        
    }
    
    public static boolean isOdd(int input){
        if(input%2==0)
            return false;
        else
            return true;
    }
    
    public static boolean isPowerOfTwo(int input){
        if(input==0)
            return false;
        while(input%2==0)
            input/=2;
        if(input==1) return true;
        else return false;
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package recursivefizzbuzz;

/**
 *
 * @author fury
 */
public class RecursiveFizzBuzz {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        fizzbuzz(100);
    }
    //div 3= fizz, div 5=buzz div both = fizzbuzz
    public static void fizzbuzz(int num){
       if(num!=0){
	    if(num%15==0)
		System.out.println("fizzbuzz");
	    else if(num%5==0)
		System.out.println("buzz");
	    else if(num%3==0)
		System.out.println("fizz");
	    else
		System.out.println(num);
	    fizzbuzz(num-1);
       }
    }
}

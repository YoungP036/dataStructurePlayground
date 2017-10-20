/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reversestring;

import java.util.Scanner;

/**
 *
 * @author fury
 */
public class ReverseString {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
	Scanner keyboard = new Scanner(System.in);
	String input;
	while(true){
	    StringBuilder newString=new StringBuilder();
	    System.out.print("\nEnter a string\n>>");
	    input=keyboard.next();
	    if(input.equals("-1"))
		break;
	    else
		for(int i=input.length()-1;i>=0; i--){
		    newString.append(input.charAt(i));
		}
	    System.out.println(newString);
	}
    }
    
}

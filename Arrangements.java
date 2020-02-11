
import java.util.Scanner;
 
public class Arrangements 
{
    static void arrange(int[] arr, int k) 
    {
        if(k==arr.length) 
        {
            for(int i=0; i<arr.length; i++) 
            {
            		System.out.print(arr[i] + " ");
            }
            System.out.println();
            System.out.println("k: " + k + "---------------");
        } 
        else 
        {
            for(int i=k; i<arr.length; i++) 
            {	
            	//System.out.println("Begin of loop: " + k);//THIS
                int temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
                
                //System.out.println("temp: " + temp + " " + "arr[k]: " + arr[k] + " " + "arr[i]: " + arr[i]);
                
				
            	//System.out.println("k: " + k);
            	
            	//System.out.println("just before recursion method, k:" + k);//THIS
            	//System.out.println("array: " + arr[0] + "" + arr[1] + "" + arr[2]);//THIS
            	
				/*
				 * for(int s=0; s<k; s++) System.out.print(arr[s] + ""); System.out.println();
				 */
            	
                arrange(arr, k+1);  //recursion
                
                //System.out.println("k+1: " + (k+1));
                //System.out.println("After recursion line, k: " + k); //THIS
                //System.out.println("array: " + arr[0] + "" + arr[1] + "" + arr[2]);//THIS
                
                temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
                
                //System.out.println("temp: " + temp + " " + "arr[k]: " + arr[k] + " " + "arr[i]: " + arr[i]);
                
            }
        }
    }
 
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of list: ");
        int n = sc.nextInt();
        int[] sequence = new int[n];
 
        for(int i=0; i<n; i++)
        {
        	 sequence[i] = sc.nextInt();
        }
           
        System.out.println("The original sequence is: ");
        for(int i=0;i<n; i++)
        {
        	 System.out.print(sequence[i] + " ");
        }
        	
        System.out.println("\nThe arranged sequences are: ");
        arrange(sequence, 0);
 
        sc.close();
    }
}
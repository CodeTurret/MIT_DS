
import java.util.ArrayList;
import java.util.Scanner;
 
public class Combination 
{
	static int count=0;
	static int setNo=0;
	static int x=0;
	static String l = "";
	static ArrayList<String> finalList = new ArrayList<String>();
	
	static void printDistinctStrings(String arr[], int n) 
    { 
		int c=0;
		String s1 ="";
		String s2 ="";
		for(int i=0; i<n; i++)
		{
			if(i==0 && finalList.size()==0)
			{
				finalList.add(arr[i]);
			}
			else
			{
				for(int j=0; j<finalList.size(); j++)
				{
					s1 = arr[i];
					s2 = finalList.get(j);
					System.out.println("Comparing: " + s1 + " " + s2);
					if(!s1.equals(s2))
					{
						c++;
					}
					
				}
				if(c>0)
				{
					finalList.add(s1);
					System.out.println("ADDED");
					break;
				}
			}
		}
		System.out.println("Finally: ");
		for(int a=0; a<finalList.size(); a++)
		{
			System.out.println(finalList.get(a));
		}
    } 
	
	
	static void countDistinct(int arr[], int n) 
    { 
        // Pick all elements one by one 
        for (int i = 0; i < n; i++) 
        { 
            // Check if the picked element  
            // is already printed 
            int j; 
            for (j = 0; j < i; j++) 
            if (arr[i] == arr[j])
            {
            	 count++;
            	 break;
            } 
        } 
    } 
	
	static void printDistinct(int arr[], int n) 
    { 
        // Pick all elements one by one 
        for (int i = 0; i < n; i++) 
        { 
            // Check if the picked element  
            // is already printed 
            int j; 
            for (j = 0; j < i; j++) 
            if (arr[i] == arr[j])
            {
            	 count++;
            	 break;
            } 
      
            // If not printed earlier,  
            // then print it 
            if (i == j) 
            System.out.print( arr[i] + " "); 
        } 
    } 
	
    static void arrange(int[] arr, int k) 
    {
        if(k==arr.length) 
        {	
            for(int i=0; i<arr.length; i++) 
            {
            		l = l + arr[i];
            		System.out.print(arr[i] + " "); //output
            }
            l = l + ",";
        
            
            System.out.println(); //output
            setNo++;
        } 
        else 
        {
            for(int i=k; i<arr.length; i++) 
            {	
                int temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
            	
                arrange(arr, k+1);  //recursion
                
                temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
            }
        }
    }
 
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Please enter the set of numbers: ");
        String set = sc.nextLine();
        
        String[] strArray = set.split(",");
        int[] numbers = new int[strArray.length];
        for(int i = 0; i < strArray.length; i++)
        {
            numbers[i] = Integer.parseInt(strArray[i]);
        }
        
        int n = numbers.length;  
        System.out.println("The original set of numbers: ");
        for(int i=0; i<numbers.length; i++)
        {
        	 System.out.print(numbers[i] + " ");
        }
        	
        countDistinct(numbers, numbers.length);
        
        System.out.println("\nThe arranged sets of numbers: ");
        //System.out.println("Count: " + count);
        if(count==0) //all distinct numbers
        {
        	 arrange(numbers, 0);
        }
        else if(count==(n-1)) //all same numbers
        {
        	printDistinct(numbers, numbers.length);
        }
        else if(count>=1)
        {
        	arrange(numbers, 0);
        	
        	//System.out.println("Total list: " + l);
        	
        	String[] strArr = l.split(",");
        	
            String[] result = new String[strArr.length];
            //System.out.println("Unsolved Result: ");
            for(int i = 0; i <result.length; i++)
            {
                result[i] = strArr[i];
                //System.out.println(result[i]);
            }
       	    
            //printDistinctStrings(result, result.length);
            
       	 
        }
        //System.out.println("Total number of arranged sets of numbers: " + setNo);
        
        sc.close();
    }
}
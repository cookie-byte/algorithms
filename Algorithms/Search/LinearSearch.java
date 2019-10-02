package hacoberfest;

import java.util.Scanner;
public class LinearSearch{
    
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the size of the list for searching");
        int size=scan.nextInt();

        int arr[]=new int[size];

        System.out.println("Enter elements");
        for(int i=0;i<size;i++)
        {
            arr[i]=scan.nextInt();
        }

        System.out.println("Enter the element to be searched");
        int element=scan.nextInt();
        
        System.out.println("Searching for "+element+" ..............");

        LinearSearch obj=new LinearSearch();
        obj.linearSearch(arr,element);
    }

    public void linearSearch(int arr[],int element)
    {
        int i=0;
        while(i<arr.length)
        {
            if(arr[i]==element)
            break;
            
            i++;
        }

        if(i==arr.length)
        {
            System.out.println("The element you are looking for could not be found");
        }
        else{
            System.out.println("The element you are looking for was found at index = "+(i+1));
        }

    }
}
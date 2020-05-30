import java.io.*; 
class source_dest
{ 
    public static void main(String args[]) 
    throws FileNotFoundException,IOException 
    { 
        // taking input from console and thrwoing an error if file doesn't exist
        FileInputStream fin = new FileInputStream(args[0]); 
  
        /* assuming that the file exists and need not to be 
           checked */
        FileOutputStream fout = new FileOutputStream(args[1]); 
  
        int b; 
        while  ((b=fin.read()) != -1) 
            fout.write(b); 
  
        /* read() will readonly next int so while 
           loop is used here in order to read upto end of file and 
           keep writing the read int into dest file */
        fin.close(); 
        fout.close(); 
	System.out.println("Finished with copying...exiting");
    } 
} 
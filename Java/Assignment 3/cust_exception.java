   class cust_exception{  
      
       static void match(String t)throws NoMatchException{  
         if(t!="India")  
          throw new NoMatchException(" Match not found");
         else  
          System.out.println("Match found");  
       }  
         
       public static void main(String args[]){  
          try{  
          match("China");  
          }catch(Exception m){System.out.println("Exception occured: "+m);}  
      
          System.out.println("exiting...");  
      }  
    }

    class NoMatchException extends Exception{  
     NoMatchException(String s){  
      super(s);  
     }  
    }  
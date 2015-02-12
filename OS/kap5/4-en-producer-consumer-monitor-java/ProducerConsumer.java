import java.util.*;
import java.io.*;

public class ProducerConsumer {

    public static void main (String [] args) {
	Buffer buf = new Buffer();
    
	// create new threads
	Thread prod = new Producer(10000, buf);
	Thread cons = new Consumer(10000, buf);
    
	// starting threads
	prod.start();
	cons.start();
    
	// Wait for the threads to finish
	try {
	    prod.join();
	    cons.join();
	} catch (InterruptedException e) {return;}
    }
 
} 

// The following object behaves as a monitor since its methods are synchronized
class Buffer {
    private int[] buffer = new int[20]; 
    private int j,bufidx=0;
    private boolean empty = true;
  		
    public synchronized void put (int i) throws InterruptedException { 
	while (bufidx == 19) {
	    try { wait(); }
	    catch (InterruptedException e) {throw e;}
	}
        buffer[bufidx]=1;
	bufidx++;
	j=0;
	System.out.print("Producer: " + bufidx);
        while(j < bufidx) { j++; System.out.print("="); }
	System.out.println("");
	notify();
    } 
  		
    public synchronized int get () throws InterruptedException {
	while (bufidx == 0)  {
	    try { 	wait(); }
	    catch (InterruptedException e) {throw e;}
	}
	buffer[bufidx]=0;
	bufidx--;
	j=0;
	System.out.print("Consumer: " + bufidx);
        while(j < bufidx) { j++; System.out.print("="); }
	System.out.println("");
	notify();
	return bufidx;
    }
}



import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class Test1 {
	public List<File> files=new ArrayList<File>();
	
	public void traverse( File file ) {
	      if( file.isDirectory() ) {
	         String entries[] = file.list() ;
	         if( entries != null ) {
	            for( String entry : entries ) {
	               traverse( new File(file,entry) ) ;
	            }
	         }
	      } else {
	    	  files.add(file);
	      }
	      
	}
	
	public void out(){
		files.forEach(System.out::println);
	}
	
	

	public static void main(String[] args) {
		Test1 t = new Test1();
		t.traverse(new File("/home/ray/java_schulung/Html"));
		t.out();

	}

}

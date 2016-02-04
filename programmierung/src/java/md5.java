import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Test1 {
	public List<File> files=new ArrayList<File>();
	
	public List<Map<String,String>> files_hash= new ArrayList<Map<String,String>>();
	
	private String getFileChecksum(MessageDigest digest, File file) throws IOException
	{
	    FileInputStream fis = new FileInputStream(file);
 
	    byte[] byteArray = new byte[1024];
	    int bytesCount = 0; 
	    
	    bytesCount = fis.read(byteArray);  // read only max first 1024 bytes
	    digest.update(byteArray, 0, bytesCount);
	    
	    fis.close();
	    
	    byte[] bytes = digest.digest();
	    
	    StringBuilder sb = new StringBuilder();
	    for(int i=0; i< bytes.length ;i++) {
	        sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
	    }
	    return sb.toString();
	}
	
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
		
		try {
			MessageDigest md5Digest = MessageDigest.getInstance("MD5");
			System.out.println(t.getFileChecksum(md5Digest, t.files.get(2)));
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

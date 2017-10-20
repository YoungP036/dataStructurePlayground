
package phonenumformatchangewithregex;
/*
change (232) 511-7623 to {232}.511.7623
assumptions: we know the current pattern
*/
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.*;

public class PhoneNumFormatChangeWithRegex {

    public static void main(String[] args) throws IOException {
        FileInputStream fp=null;
        BufferedReader in = null;
        FileOutputStream out=null;
        try {
            fp = new FileInputStream("phonelist.txt");
            in = new BufferedReader(new InputStreamReader(fp));
            out = new FileOutputStream("newphonelist.txt");
            String line;
            while((line=in.readLine()) != null){
                line = line.replaceAll("[(]","{");
                line = line.replaceAll("[)]","}");
                line = line.replaceAll("[ -]",".");
                System.out.println(line);
                
            }
        }
        finally{
            if(in!=null)
                in.close();
            if(out!=null)
                out.close();
            if(in!=null)
                in.close();
        }
    }
    
}

import java.io.*;
class quotes
{
   public static void main(String args[])throws IOException
    { String str="";
    int c=0,f=0;
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int n=Integer.parseInt(br.readLine());
    if(n<1 ||n>50)
    {
     
        return;
    }
    for(int i=1;i<=n;i++)
    {
        String s=br.readLine();
        str=s+" ";
        for(int j=0;j<str.length();j++)
       {c=s.length();
          if(str.charAt(j)!=' ' || str.charAt(j)<97)
          continue;
        if(c<1 || c>100)
        continue;
       }
    if(s.indexOf(" not ")!=-1 || s.indexOf("not ")==0 ||  s.lastIndexOf(" not")==s.length()-4 )
        System.out.println("Real Fancy");
       else 
        System.out.println("regularly fancy");
        
          
        
    }
}
}
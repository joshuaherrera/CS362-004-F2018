

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   UrlValidator testURL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //all return true
	   String[] validInputPartitionScheme = {"http://www.google.com", 
			   "ftp://www.foo.com",
			   "http://www.bar.com",
			   "http://www.foobar.com",
			   "http://www.osu.com"};
	   boolean res = false;
	   for(int i = 0; i < validInputPartitionScheme.length; i++)
	   {
		   try {res = testURL.isValid(validInputPartitionScheme[i]);}
		   catch(Error e)
		   {System.out.println(validInputPartitionScheme[i]+" caused "+e);} 
	       System.out.println(validInputPartitionScheme[i]+" returned "+res); 
	   }
	   //all return false
	   String[] validInputPartitionNoScheme = {"www.google.com", 
			   "www.foo.com",
			   "www.bar.com",
			   "www.foobar.com",
			   "www.osu.com"};
	   res = false;
	   for(int i = 0; i < validInputPartitionNoScheme.length; i++)
	   {
		   try {res = testURL.isValid(validInputPartitionNoScheme[i]);}
		   catch(Error e)
		   {System.out.println(validInputPartitionNoScheme[i]+" caused "+e);} 
	       System.out.println(validInputPartitionNoScheme[i]+" returned "+res); 
	   }
	   
       
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	
	   UrlValidator testURL = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //these all return true
	   String[] invalidInputPartitionScheme = {"http://www..com", 
			   "http://www.com",
			   "http://www.bar.com.com",
			   "http://ww.foobar.com",
			   "http://www.osu.",
			   "http://"};
	   boolean res = false;
	   for(int i = 0; i < invalidInputPartitionScheme.length; i++)
	   {
		   try {res = testURL.isValid(invalidInputPartitionScheme[i]);}
		   catch(Error e)
		   {System.out.println(invalidInputPartitionScheme[i]+" caused "+e);} 
	       System.out.println(invalidInputPartitionScheme[i]+" returned "+res); 
	   }
	   //these all return false
	   String[] invalidInputPartitionNoScheme = {"www..com", 
			   "www.com",
			   "www.bar.com.com",
			   "ww.foobar.com",
			   "www.osu."};
	   res = false;
	   for(int i = 0; i < invalidInputPartitionNoScheme.length; i++)
	   {
		   try {res = testURL.isValid(invalidInputPartitionNoScheme[i]);}
		   catch(Error e)
		   {System.out.println(invalidInputPartitionNoScheme[i]+" caused "+e);} 
	       System.out.println(invalidInputPartitionNoScheme[i]+" returned "+res); 
	   }

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}



import junit.framework.TestCase;
import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

class ResultPair{
   public String strToTest;
   public boolean result;

   public ResultPair(String strToTest, boolean result)
   {
      this.strToTest = strToTest;
      this.result = result;
   }
}

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
      UrlValidator urlVal1 = new UrlValidator(null, null, 1);
      String str4 = "HTTP://SomeurlThatShouldWork.Org";
      assertTrue(urlVal1.isValid(str4));

      String str5 = "https:/thisurlisbad.something";
      assertFalse(urlVal1.isValid(str5));

      String str6 = "h3t://anotherUrl.org";
      assertTrue(urlVal1.isValid(str6));

      //Testing a single capital character in the URL
      String str7 = "https://Acapitalletter.com";
      assertTrue(urlVal1.isValid(str7));

      //Testing single capital character in scheme section of URL"
      String str8 = "Https://lowercasebody.org";
      assertTrue(urlVal1.isValid(str8));

      //Testing null case
      assertFalse(urlVal1.isValid("null"));

      assertFalse(urlVal1.isValid("http://259.259.259"));

      assertTrue(urlVal1.isValid("http://166.179.200"));

      assertTrue(urlVal1.isValid("http://2602:1c0:8001:1d3:6d1c:fb57:d9e5:438c"));

      //Alphanumeric character combination in URL
      assertTrue(urlVal1.isValid("http://url7.com"));

      //IP-address type URL
      assertTrue(urlVal1.isValid("166.154.232"));

      //Scheme (in this case http) in the middle part of the URL
      assertTrue(urlVal1.isValid("aurl.http://someUrl"));
   }
   
   public void testYourFirstPartition()
   {
      UrlValidator urlVal = new UrlValidator(null, null, 1);
      assertTrue(urlVal.isValid("http://aurl.org"));
      assertTrue(urlVal.isValid("ftp://oregonstate.edu"));
   }
   
   public void testYourSecondPartition(){
      UrlValidator urlVal = new UrlValidator(null, null, 1);
      assertTrue(urlVal.isValid("ftp://anotherurl.com"));
   }
   
   public void testIsValid()
   {
      Random rand = new Random();

      ResultPair[] schemes = {
              new ResultPair("http://", true),
              new ResultPair("httt://", true), // misspelling
              new ResultPair("ftp:/", false), // missing slash
              new ResultPair("ftp://", true),
              new ResultPair("file://", true),
              new ResultPair("", true),
      };
      ResultPair[] authorities = {
              new ResultPair("SomeurlThatShouldWork.com", true),
              new ResultPair("asdasd\\\\.aqwq", false), // invalid chars
              new ResultPair("2602:1c0:8001:1d3:6d1c:fb57:d9e5:438c", true),
              new ResultPair("192.168.1.1", true),
              new ResultPair("192.168.1.256", false), // too big
              new ResultPair("192.168.1.2.3", false), // too big
      };
      ResultPair[] ports = {
              new ResultPair("", true),
              new ResultPair(":90", true),
              new ResultPair(":65510", true),
              new ResultPair(":65536", false), // too big
              new ResultPair(":-1", false), // to small

      };
      ResultPair[] paths = {
              new ResultPair("/", true),
              new ResultPair("/test/", true),
              new ResultPair("/test/cool/this/", true),
              new ResultPair("/http://", true),
              new ResultPair("/../", false), // invalid chars
              new ResultPair("/#/", false), // invalid chars
      };

      UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

      for (int i = 0; i < 1000; i++)
      {
         // get random picks from lists
         ResultPair scheme = schemes[rand.nextInt(schemes.length)],
                    authority = authorities[rand.nextInt(authorities.length)],
                    port = ports[rand.nextInt(ports.length)],
                    path = paths[rand.nextInt(paths.length)];

         // only if they are all valid with the whole url be valid
         boolean result = scheme.result & authority.result & port.result & path.result;
         String url = scheme.strToTest + authority.strToTest + port.strToTest + path.strToTest;

         assertEquals(result, urlValidator.isValid(url));
      }
   }
}

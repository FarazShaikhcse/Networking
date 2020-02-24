import org.openqa.selenium.WebDriver;
import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
public class thing {

  public static void main(String[] args) {
	System.setProperty("webdriver.gecko.driver","C:\\Users\\Karthik\\Downloads\\geckodriver-v0.26.0-win64\\geckodriver.exe");
    String baseUrl = "https://www.facebook.com/";

    WebDriver driver=new FirefoxDriver();
    driver.manage().window().maximize();


    driver.get(baseUrl);


    List<WebElement> radio = driver.findElements(By.cssSelector("input._8esa"));
    WebElement femaleradio = radio.get(0);
    Boolean femalepresent = femaleradio.isDisplayed();
    if (true == femalepresent)
    	System.out.println("Female radio button is present");
    else
	    System.out.println("Female radio button is absent");

    WebElement maleradio = radio.get(1);
    Boolean malepresent = maleradio.isDisplayed();
    if (true == malepresent)
    	System.out.println("Male radio button is present");
    else
	    System.out.println("Male radio button is absent");    

    WebElement email = driver.findElement(By.id("email"));
    WebElement password = driver.findElement(By.id("pass"));

    email.clear();
    email.sendKeys("9071977668");

    password.clear();
    password.sendKeys("someone123");

    WebElement login = driver.findElement(By.id("loginbutton"));
    login.click();

    System.out.println("Log in successful");


    try {Thread.sleep(5000);} catch (Exception e) {}


    List<WebElement> News = driver.findElements(By.cssSelector("a._5afe"));
    WebElement NewsFeed = News.get(1); 
    NewsFeed.click();

    try {Thread.sleep(3000);} catch (Exception e) {}

    System.out.println("News Feed section opened");


    WebElement CreatePost = driver.findElement(By.cssSelector("span._5qtp"));
    CreatePost.click();

    System.out.println("Create Post clicked");
    try {Thread.sleep(2000);} catch (Exception e) {}

    WebElement WritePost = driver.findElement(By.cssSelector("div.notranslate._5rpu"));
    WritePost.click();
    WritePost.sendKeys("Selenium Testing");

    try {Thread.sleep(2000);} catch (Exception e) {}

    WebElement PostButton = driver.findElement(By.cssSelector("button._1mf7._4r1q._4jy0._4jy3._4jy1._51sy.selected._42ft"));
    PostButton.click();

    System.out.println("Posted status");

    try {Thread.sleep(3000);} catch (Exception e) {}

    WebElement navigation = driver.findElement(By.id("userNavigationLabel"));
    navigation.click();

    try {Thread.sleep(3000);} catch (Exception e) {}

    WebElement logout = driver.findElement(By.cssSelector("li.54ni.navSubmenu._6398._64kz._MenuItem"));
    logout.click();

    System.out.println("Log out successful");

    driver.close();
  }
}

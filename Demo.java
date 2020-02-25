import java.io.IOException;

import org.openqa.selenium.*;
import org.openqa.selenium.firefox.FirefoxDriver;
public class UD {
    public static void main(String[] args) {
        System.setProperty("webdriver.gecko.driver","/home/student/geckodriver");
        String baseUrl = "http://demo.guru99.com/test/upload/";
        WebDriver driver = new FirefoxDriver();
        
        //maximize the window
        driver.manage().window().maximize();

        //Perform file upload
        System.out.println("Perform upload");
        driver.get(baseUrl);
        WebElement uploadElement = driver.findElement(By.id("uploadfile_0"));

        // enter the file path onto the file-selection input field
        uploadElement.sendKeys("/home/student/parta4.txt");
        System.out.println("File path entered");

        // check the "I accept the terms of service" check box
        driver.findElement(By.id("terms")).click();
        System.out.println("Checked the \"I accept the terms of service\" check box");

        // click the "Submit File" button
        driver.findElement(By.name("send")).click();
        System.out.println("Clicked the \"Submit File\" button");
        
        //Perform file download
        System.out.println("Perform download");
        baseUrl = "http://demo.guru99.com/test/yahoo.html";
        driver.get(baseUrl);
        
        WebElement downloadButton = driver.findElement(By.id("messenger-download"));
        String sourceLocation = downloadButton.getAttribute("href");
        System.out.println("Download location is "+ sourceLocation);
        String wget_command = "wget " + sourceLocation;

        try
        {
        	Process exec = Runtime.getRuntime().exec(wget_command);
            int exitVal = exec.waitFor();
            System.out.println("Exit value: " + exitVal);
            if (0 == exitVal)
            	System.out.println("File downloaded successfully from location "+ sourceLocation);
        }
        catch (InterruptedException | IOException ex)
        {
        	System.out.println(ex.toString());
        }
        driver.close();
        }
}

package shop;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class Shop {
	/**
	 * 
	ProductStock.shopStock. * @param args
	 */
	public static void main(String[] args) {
		Customer customer1 = new Customer("Donal", 12);
		Product product = new Product();
		Shop shop = new Shop();
		shop.readAndStore(product);
		product.printProducts();
		//System.out.println(product.stock());
		//System.out.println(product.price());
		//product.removeProdQuan("Bread", 12);
		//System.out.println(product.stock());
	}
	/**
	 * This void method will read the a CSV file and in a interface called ProductStore
	 * No return
	 */
	public void readAndStore(Product product) {
		String line = "";
		//Product product = new Product();
		BufferedReader br;
		// try the code if the file cant be read, then catch the exception
		try {
			br = new BufferedReader(new FileReader("stockJava.csv"));
			// returns a Boolean value
			while ((line = br.readLine()) != null) {
				// get the first cell and assign to dict as key
				// parsing the second cell as a string as an int value
				//populate Dictionary stock with key = name and value = quanitity 
				product.addToStock(line.substring(0, line.indexOf(",")),
						Double.parseDouble(line.substring(line.lastIndexOf(",")+1, line.length())));
				//populate Dictionary price with key = name and value = price
				product.addToPrice(line.substring(0, line.indexOf(",")),
						Double.parseDouble(line.substring(line.indexOf(",")+1, line.lastIndexOf(","))));
			}
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("File exception IO error");
		}
	}
}

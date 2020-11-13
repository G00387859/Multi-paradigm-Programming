package shop;

import java.util.Dictionary;
import java.util.Enumeration;

public class Product implements ProductStock {
	private Enumeration<String> name;
	private Enumeration<Double> price;
	private Enumeration<Double> quantity;

	// no parameter constructor
	public Product() {
	}

	/**
	 * loops over both Dictionary and will display the stock to the customer.
	 * Private variables have to be of type Enum
	 */
	public void printProducts() {
		name = ProductStock.shopStock.keys();
		price = ProductStock.shopPrice.elements();
		quantity = ProductStock.shopStock.elements();
		// Displaying the Enumeration
		while (name.hasMoreElements()) {
			// formatter can be difficult to read. Product name: Coke can, Product quantity:
			// Product quantity, Product price: Product price
			System.out.printf("%s: %s\n%s: %.0f\n%s: \u20ac%.2f\n\n", "Product Name", name.nextElement(),
					"Product quantity", quantity.nextElement(), "Product price", price.nextElement());
		}
	}

	/**
	 * @param key
	 * @param d   Integer from the wrapper class
	 */
	public void addToStock(String key, double d) {
		ProductStock.shopStock.put(key, d);
	}

	public void addToPrice(String key, Double value) {
		ProductStock.shopPrice.put(key, value);
	}

	/**
	 * 
	 * @param na the name and the key.
	 * @param q  as the q = quantity to s
	 */
	// remove a quantity from a product
	public void removeProdQuan(String na, int q) {
		Object check = ProductStock.shopStock.get(na);
		if ((Integer) check != 0) {
			ProductStock.shopStock.put(na, (Double) check - q);
		} else {
			System.out.println("Sorry stock is too low");
		}
	}

	/**
	 * 
	 * @return the interface remove**** before when dev is completed
	 */
	public Dictionary<String, Double> stock() {

		return ProductStock.shopStock;
	}

	public Dictionary<String, Double> price() {

		return ProductStock.shopPrice;
	}

}

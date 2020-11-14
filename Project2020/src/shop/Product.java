package shop;

import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Scanner;

public class Product implements ProductStock {
	private Enumeration<String> name;
	private Enumeration<Double> price;
	private Enumeration<Integer> quantity;
	protected double productsTotal = 0.0;
	ArrayList<String> arrkeys = new ArrayList<String>();

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
			System.out.printf("%s: %s\n%s: %d\n%s: \u20ac%.2f\n\n", "Product Name", name.nextElement(),
					"Product quantity", quantity.nextElement(), "Product price", price.nextElement());
		}
	}

	public Dictionary Order() {
		Dictionary<String, Integer> custOrder = new Hashtable<String, Integer>();
		// arraylist of keys.

		Scanner customerOrder = new Scanner(System.in); // Create a Scanner object
		Scanner OrderQuantity = new Scanner(System.in); // Create a Scanner object
		while (true) {
			System.out.println("Please enter product name or exit to exit");

			String choice = customerOrder.nextLine().toLowerCase().trim(); // Read user input
			System.out.println("Customer choice is: " + choice); // Output user input

			if (choice.equals("spaghetti")) {
				System.out.println("Price is: \u20ac" + ProductStock.shopPrice.get("Spaghetti") + " Shop stock "
						+ ProductStock.shopStock.get("Spaghetti"));
				System.out.println("Enter the quantity");
				int choice1 = Integer.parseInt(customerOrder.nextLine()); // Read user input
				productsTotal += choice1 * ProductStock.shopPrice.get("Spaghetti");
				System.out.println("Customer choice is: " + choice1); // Output user input
				custOrder.put("Spaghetti", choice1);// ("spaghetti",choice1);
				arrkeys.add("Spaghetti");

			} else if (choice.equals("coke can")) {
				System.out.printf("Price is: \u20ac%.2f Shop stock %d\n", ProductStock.shopPrice.get("Coke Can"),
						ProductStock.shopStock.get("Coke Can"));
				System.out.println("Enter the quantity");
				int choice1 = Integer.parseInt(customerOrder.nextLine()); // Read user input
				productsTotal += choice1 * ProductStock.shopPrice.get("Coke Can");
				System.out.println("Customer choice is: " + choice1); // Output user input
				custOrder.put("Coke Can", choice1);// ("spaghetti",choice1);
				arrkeys.add("Coke Can");

			} else if (choice.equals("bread")) {
				System.out.printf("Price is: \u20ac%.2f Shop stock %d\n", ProductStock.shopPrice.get("Bread"),
						ProductStock.shopStock.get("Bread"));
				System.out.println("Enter the quantity");
				int choice1 = Integer.parseInt(customerOrder.nextLine()); // Read user input
				productsTotal += choice1 * ProductStock.shopPrice.get("Bread");
				System.out.println("Customer choice is: " + choice1); // Output user input
				custOrder.put("Bread", choice1);// ("spaghetti",choice1);
				arrkeys.add("Bread");
			} else if (choice.equals("tomato sauce")) {
				System.out.println("Price is: \u20ac" + ProductStock.shopPrice.get("Tomato Sauce") + " Shop stock "
						+ ProductStock.shopStock.get("Tomato Sauce"));
				System.out.println("Enter the quantity");
				int choice1 = Integer.parseInt(customerOrder.nextLine()); // Read user input
				productsTotal += choice1 * ProductStock.shopPrice.get("Tomato Sauce");
				System.out.println("Customer choice is: " + choice1); // Output user input
				custOrder.put("Tomato Sauce", choice1);// ("spaghetti",choice1);
				arrkeys.add("Tomato Sauce");
			} else if (choice.equals("bin bags")) {
				System.out.println("Price is: \u20ac" + ProductStock.shopPrice.get("Bin Bags") + " Shop stock "
						+ ProductStock.shopStock.get("Bin Bags"));
				System.out.println("Enter the quantity");
				int choice1 = Integer.parseInt(customerOrder.nextLine()); // Read user input
				productsTotal += choice1 * ProductStock.shopPrice.get("Bin Bags");
				System.out.println("Customer choice is: " + choice1); // Output user input
				custOrder.put("Bin Bags", choice1);// ("spaghetti",choice1);
				arrkeys.add("Bin Bags");
			} else {
				break;
			}
		}
		return custOrder;
	}

	/**
	 * @param key
	 * @param d   Integer from the wrapper class
	 */
	public void addToStock(String key, int d) {
		ProductStock.shopStock.put(key, d);
	}

	public void addToPrice(String key, Double value) {
		ProductStock.shopPrice.put(key, value);
	}

	public void updateStock(Dictionary dict) {
		System.out.println("Debug updateStock in updateStock" );
		int len = dict.size();
		int update = 0;
		int current =0;
		String name = "";
		int curKeyValue=0;
		//System.out.println("Debug updateStock len " + len);
		// String = dict.elements();
		//System.out.println("updateStock dict " + dict);
		for (int i = 0; i < len; i++) {
			name = arrkeys.get(i);
			//System.out.println("updateStock name " + name);
			//System.out.println(" updateStock dict.get(name)" + dict.get(name));
			curKeyValue = (Integer)dict.get(name);
			//System.out.println("Debug updateStock 1 arrkeys.get(i) " + arrkeys.get(i));
			current = ProductStock.shopStock.get(name);
			//System.out.println("Debug updateStock current " +current);
			//System.out.println("debug point 2 current" + (int)dict.get(arrkeys.get(i)));
			update = current - curKeyValue;
			//System.out.println("Debug point 2 for updateStock update"+ update);
			ProductStock.shopStock.put(arrkeys.get(i), update);
			//System.out.println("Debug updateStock final see updated stock " + ProductStock.shopStock.get(name));
			
		}
	}

	/**
	 * 
	 * @param na the name and the key.
	 * @param q  as the q = quantity to s
	 */
	// remove a quantity from a product
	public void removeProdQuan(String na, int q) {
		Object check = ProductStock.shopStock.get(na);
		System.out.println("check " + check);
		if ((Integer) check != 0) {
			ProductStock.shopStock.put(na, (Integer) check - q);
		} else {
			System.out.println("Sorry stock is too low");
		}
	}

	/**
	 * 
	 * @return the interface remove**** before when dev is completed
	 */
	public Dictionary<String, Integer> stock() {

		return ProductStock.shopStock;
	}

	public Dictionary<String, Double> price() {

		return ProductStock.shopPrice;
	}

}

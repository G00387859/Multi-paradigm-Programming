package shop;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Product implements ProductStock {
//	private Enumeration<String> name;
//	private Enumeration<Double> price;
//	private Enumeration<Integer> quantity;
	private Set<String> stockKeys = ProductStock.shopStock.keySet();
	public double getProductsTotal() {
		return productsTotal;
	}

	private Collection<Integer> stockValues = ProductStock.shopStock.values();
	private Collection<Double> priceValues = ProductStock.shopPrice.values();
	private double productsTotal = 0.0;
	ArrayList<String> arrkeys = new ArrayList<String>();

	// no parameter constructor
	public Product() {
	}

	/**
	 * loops over both Dictionary and will display the stock to the customer.
	 * Private variables have to be of type Enum
	 */
	public void printProducts() {
		System.out.println("**** Products in stock ****");
		Iterator<String> name = stockKeys.iterator();
		Iterator<Integer> quantity = stockValues.iterator();
		Iterator<Double> price = priceValues.iterator();
		while (name.hasNext()) {
			// formatter can be difficult to read. Product name: Coke can, Product quantity:
			// Product quantity, Product price: Product price
			System.out.printf("%s: %s\n%s: %d\n%s: \u20ac%.2f\n\n",
					"Product Name", name.next(), 
					"Product quantity", quantity.next(), 
					"Product price", price.next());

		}
	}

	public HashMap<String, Integer> Order() {
		HashMap<String, Integer> custOrder = new HashMap<String, Integer>();
		// arraylist of keys.

		Scanner customerOrder = new Scanner(System.in); // Create a Scanner object
		Scanner OrderQuantity = new Scanner(System.in); // Create a Scanner object
		int exit =1;
		while (exit != 0) {
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
				System.out.printf("Price is: \u20ac%.2f Shop stock %d\n", ProductStock.shopPrice.get("Tomato Sauce"),
						ProductStock.shopStock.get("Tomato Sauce"));
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
			} else if (choice.equals("exit")){
				System.out.println("Customer choice is exit! "); // Output user input
				exit =0;
			}
		}
		return custOrder;
	}

	public HashMap BulkOrder(String fileName) {
		HashMap<String, Integer> bulkOrder = new HashMap<String, Integer>();
		HashMap<String, Integer> custOrder = new HashMap<String, Integer>();
		// arraylist of keys.
		String line = "";
		BufferedReader br;
		// try the code if the file cant be read, then catch the exception
		try {
			br = new BufferedReader(new FileReader(fileName));
			// returns a Boolean value
			while ((line = br.readLine()) != null) {
				bulkOrder.put(line.substring(0, line.indexOf(",")),
						Integer.parseInt(line.substring(line.lastIndexOf(",") + 1, line.length())));
				//System.out.println("Debug BulkOrder 1 fileReader " + line);
			}
		      for (String i : bulkOrder.keySet()) {
				//System.out.println("Debug BulkOrder 2 2nd while + i " + i);
				if (i.equals("Spaghetti")) {
					double shopPrice = ProductStock.shopPrice.get("Spaghetti");
					int shopStock = ProductStock.shopStock.get("Spaghetti");
					int CustOrder = bulkOrder.get("Spaghetti");
					if(CustOrder < shopStock) {
						System.out.println(i+": Price is: \u20ac" + ProductStock.shopPrice.get("Spaghetti") + " Shop stock "
								+ ProductStock.shopStock.get("Spaghetti"));
						// System.out.println("Enter the quantity");
						int choice1 = bulkOrder.get("Spaghetti");
						productsTotal += choice1 * ProductStock.shopPrice.get("Spaghetti");
						//System.out.println("Customer choice is: " + choice1); // Output user input
						custOrder.put("Spaghetti", choice1);// ("spaghetti",choice1);
						arrkeys.add("Spaghetti");
					}else {
						System.out.println(CustOrder + " is greater that the shop stock");
					}
				}else if (i.equals("Coke Can")) {
					double shopPrice = ProductStock.shopPrice.get("Coke Can");
					int shopStock = ProductStock.shopStock.get("Coke Can");
					int CustOrder = bulkOrder.get("Coke Can");
					if(CustOrder < shopStock) {
						System.out.printf(i+" :Price is: \u20ac%.2f Shop stock %d\n", ProductStock.shopPrice.get("Coke Can"),
								ProductStock.shopStock.get("Coke Can"));
						//System.out.println("Enter the quantity");
						int choice1 = bulkOrder.get("Coke Can");
						productsTotal += choice1 * ProductStock.shopPrice.get("Coke Can");
						//System.out.println("Customer choice is: " + choice1); // Output user input
						custOrder.put("Coke Can", choice1);// ("spaghetti",choice1);
						arrkeys.add("Coke Can");
					}else {
						System.out.println(CustOrder + " is greater that the shop stock");
					}				

				} else if (i.equals("Bread")) {
					double shopPrice = ProductStock.shopPrice.get("Bread");
					int shopStock = ProductStock.shopStock.get("Bread");
					int CustOrder = bulkOrder.get("Bread");
					if(CustOrder < shopStock) {
						System.out.printf(i+" :Price is: \u20ac%.2f Shop stock %d\n", ProductStock.shopPrice.get("Bread"),
								ProductStock.shopStock.get("Bread"));
						int choice1 = bulkOrder.get("Bread");
						productsTotal += choice1 * ProductStock.shopPrice.get("Bread");
						//System.out.println("Customer choice is: " + choice1); // Output user input
						custOrder.put("Bread", choice1);// ("spaghetti",choice1);
						arrkeys.add("Bread");
						
					}else {
						System.out.println(CustOrder + " is greater that the shop stock");
					}
					
					
				} else if(i.equals("Tomato Sauce")) {
					double shopPrice = ProductStock.shopPrice.get("Tomato Sauce");
					int shopStock = ProductStock.shopStock.get("Tomato Sauce");
					int CustOrder = bulkOrder.get("Tomato Sauce");
					if(CustOrder < shopStock) {
						System.out.printf(i+" :Price is: \u20ac%.2f Shop stock %d\n",
								ProductStock.shopPrice.get("Tomato Sauce"), ProductStock.shopStock.get("Tomato Sauce"));
						//System.out.println("Enter the quantity");
						int choice1 = bulkOrder.get("Tomato Sauce");
						productsTotal += choice1 * ProductStock.shopPrice.get("Tomato Sauce");
						//System.out.println("Customer choice is: " + choice1); // Output user input
						custOrder.put("Tomato Sauce", choice1);// ("spaghetti",choice1);
						arrkeys.add("Tomato Sauce");
					}else {
						System.out.println(CustOrder + " is greater that the shop stock");
					}
					
				}else if (i.equals("Bin Bags")) {
					double shopPrice = ProductStock.shopPrice.get("Tomato Sauce");
					int shopStock = ProductStock.shopStock.get("Tomato Sauce");
					int CustOrder = bulkOrder.get("Tomato Sauce");
					if(CustOrder < shopStock) {
						System.out.println(i+" :Price is: \u20ac" + ProductStock.shopPrice.get("Bin Bags") + " Shop stock "
								+ ProductStock.shopStock.get("Bin Bags"));
						//System.out.println("Enter the quantity");
						int choice1 = bulkOrder.get("Bin Bags");
						productsTotal += choice1 * ProductStock.shopPrice.get("Bin Bags");
						//System.out.println("Customer choice is: " + choice1); // Output user input
						custOrder.put("Bin Bags", choice1);// ("spaghetti",choice1);
						arrkeys.add("Bin Bags");
					}else {
						System.out.println(CustOrder + " is greater that the shop stock");
						
					}
					
				} else {
					System.out.printf("sorry %s not is stock\n",i);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("File exception IO error");
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

	public void updateStock(HashMap custOrdered) {
		System.out.println("Debug updateStock in updateStock");
		int len = custOrdered.size();
		int update = 0;
		int current = 0;
		String name = "";
		int curKeyValue = 0;
		// System.out.println("Debug updateStock len " + len);
		// String = dict.elements();
		// System.out.println("updateStock dict " + dict);
		for (int i = 0; i < len; i++) {
			name = arrkeys.get(i);
			// System.out.println("updateStock name " + name);
			// System.out.println(" updateStock dict.get(name)" + dict.get(name));
			curKeyValue = (Integer) custOrdered.get(name);
			// System.out.println("Debug updateStock 1 arrkeys.get(i) " + arrkeys.get(i));
			current = ProductStock.shopStock.get(name);
			// System.out.println("Debug updateStock current " +current);
			// System.out.println("debug point 2 current" + (int)dict.get(arrkeys.get(i)));
			update = current - curKeyValue;
			// System.out.println("Debug point 2 for updateStock update"+ update);
			ProductStock.shopStock.put(arrkeys.get(i), update);
			// System.out.println("Debug updateStock final see updated stock " +
			// ProductStock.shopStock.get(name));

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
//	public Dictionary<String, Integer> stock() {
//
//		return ProductStock.shopStock;
//	}
	public HashMap<String, Integer> stock() {
		return ProductStock.shopStock;
	}

	public HashMap<String, Double> price() {

		return ProductStock.shopPrice;
	}

}

package shop;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Shop {
	/**
	 * 
	 * ProductStock.shopStock. * @param args
	 */
	public static void main(String[] args) {
		Customer customer1 = new Customer("Donal", 120);
		Product product = new Product();
		Shop shop = new Shop();
		shop.readAndStore(product);
		product.printProducts();
		ArrayList<String> arrkeys = new ArrayList<String>();
		try {
			System.out.println("******* WELCOME TO THE SHOP *******");
			while (true) {

				Scanner customer = new Scanner(System.in); // Create a Scanner object
				System.out.println(
						"Please enter 1 for standard Customer\nEnter 2 for Bulk orders\nOR\n0(zero) to exit\n");

				int choice = Integer.parseInt(customer.nextLine()); // Read user input
				System.out.println("Debug Customer choice is: " + choice); // Output user input
				if (choice == 1) {
					System.out.println("Debug Customer choice is: " + choice); // Output user input
					// call get product list
					// product.printProducts();
					shop.checkOut(product, customer1);
					// standardCustomerOrders()

				} else if (choice == 2) {
					System.out.println("Customer choice is: " + choice); // Output user input
				} else if (choice == 0) {
					System.out.println("Thank You !\nGoodbye "); // Output user input
					System.out.println("Call order review"); // Output user input
					break;
				} else {
					throw new InputMismatchException("incorrect input - You must enter 1,2 or 0.");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("user input error must be number");
		}
	}
	// System.out.println(product.stock());
	// System.out.println(product.price());
	// product.removeProdQuan("Bread", 12);
	// product.printProducts();1
	// System.out.println(product.stock());

	// create method that will ask the customer to choose the items they wish to
	// buy.
	// loop until the customer is finished.
	// return orders
	public void standardCustomerOrders(Product product) {
		// 1: Spaghetti, 2 Coke Can,3 Bin Bags, Bread,Tomato Sauce
		Scanner customer = new Scanner(System.in); // Create a Scanner object
		System.out.println("Seen the shop stock. What would you like to buy?\n");

		String choice = customer.nextLine().toLowerCase(); // Read user input
		System.out.println("Customer choice is: " + choice); // Output user input

		if (choice == "spaghetti") {
			System.out.println("Customer choice is: " + choice); // Output user input
			// call get product list
			product.Order();

		} else if (choice == "coke can") {
			System.out.println("Customer choice is: " + choice); // Output user input
			// }else if (choice == ){
			// System.out.println("Thank You !\nGoodbye "); // Output user input
			// System.out.println("Call order review"); // Output user input
			// break;
		} else {
			throw new InputMismatchException("incorrect input - You must enter 1,2 or 0.");
		}
	}

	// this will get the customer order and process it
	/**
	 * @param product
	 * @param cust
	 */
	public void checkOut(Product product, Customer cust) {
		Dictionary<String, Integer> custOrdered = new Hashtable<String, Integer>();
		// customer name and budget
		//ArrayList<String> Akeys = new ArrayList<String>();
		///Akeys = product.arrkeys;
		int budget = 0;
		int cost = 0;
		int dictSize;
		// customer order
		custOrdered = product.Order();
		// sum up the cost
		// find how many element are in the dict
		dictSize = custOrdered.size();
		// print out the order
		if (cust.getBudget() < product.productsTotal) {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Checking Budget ****");
			System.out.println("**** Sorry you do not have enough money ****");
		} else {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Budget checked! ****");
			double moneyReturned = cust.getBudget() - product.productsTotal;
			cust.setBudget(moneyReturned);
			System.out.printf("**** budget remaining \u20ac%.2f  ****",moneyReturned);
			//update stock.
			product.updateStock(custOrdered);
			System.out.println("");
			product.printProducts();
			// check if the order is within budget if true
			// then remove the total from customers budget and update the stock.
		}
	}
	/**
	 * This void method will read the a CSV file and in a interface called
	 * ProductStore No return
	 */
	public void readAndStore(Product product) {
		String line = "";
		// Product product = new Product();
		BufferedReader br;
		// try the code if the file cant be read, then catch the exception
		try {
			br = new BufferedReader(new FileReader("stockJava.csv"));
			// returns a Boolean value
			while ((line = br.readLine()) != null) {
				// get the first cell and assign to dict as key
				// parsing the second cell as a string as an int value
				// populate Dictionary stock with key = name and value = quantity
				product.addToStock(line.substring(0, line.indexOf(",")),
						Integer.parseInt(line.substring(line.lastIndexOf(",") + 1, line.length())));
				// populate Dictionary price with key = name and value = price
				product.addToPrice(line.substring(0, line.indexOf(",")),
						Double.parseDouble(line.substring(line.indexOf(",") + 1, line.lastIndexOf(","))));
			}
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("File exception IO error");
		}
	}
}
